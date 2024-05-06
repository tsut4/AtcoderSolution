# include <iostream>
using namespace std;

long long N, K;
long long A[100009]; 
long long S[100009]; // 累積和
long long R[100009]; // 左端が決まったとき、右端がどこまでいけるか

// A[l]からA[r]までの合計値
long long sum(int l, int r) {
    return S[r] - S[l - 1];
}

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 累積和をとる
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

    // しゃくとり法
    for (int i = 1; i <= N; i++) { // N番目の数字を選択する場合も含める必要があるので、A問題と違いN-1までではなく、Nまでループさせる
        // スタート地点を決める
        if (i == 1) R[i] = 0;
        else R[i] = R[i - 1];
        // ギリギリまで増やしていく
        while (R[i] < N && sum(i, R[i] + 1) <= K) {
            R[i] += 1;
        }
    }
    // 答えを求める
    long long Answer = 0;
    for (int i = 1; i <= N; i++) Answer += (R[i] - i + 1);
    cout << Answer << endl;
    return 0;
}