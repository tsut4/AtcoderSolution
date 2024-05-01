#include <iostream>
using namespace std;

long long N, K;
long long A[100009];

// 答えがx以下かを判定し、Yesであれば、true、Noであればfalseを返す
bool check(long long x) {
    long long sum = 0;
    for (int i = 1; i <= N; i++) sum += x / A[i]; // 「x ÷ A[i]」の小数点以下切り捨て
    if (sum >= K) return true;
    return false;
}

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 二分探索
    // Leftは探索範囲の左端を、Rightは探索範囲の右端を表す
    long long Left = 1, Right = 1'000'000'000;
    while (Left < Right) {
        long long Mid = (Left + Right) / 2;
        bool Answer = check(Mid);
        if (Answer == false) Left = Mid + 1; // 答えがMid + 1以上であること分かる
        if (Answer == true) Right = Mid;     // 答えがMid以下であることが分かる
    }

    // 出力(このときLeft = Rightになっている)
    cout << Left << endl;
    return 0;
}