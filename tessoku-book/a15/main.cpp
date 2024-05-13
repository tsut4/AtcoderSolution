#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力
    int N, A[100009], B[100009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 配列Tの作成
    vector<int> T;
    for (int i = 1; i <= N; i++) T.push_back(A[i]);
    sort(T.begin(), T.end());

    // 配列Tの重複を消す
    T.erase(unique(T.begin(), T.end()), T.end());

    // 答えを求める
    for (int i = 1; i <= N; i++) {
        // vector型のlower_boundは以下のような形式で書く
        // vector型の添え字は0から始まるので、1を足す必要がある。
        B[i] = lower_bound(T.begin(), T.end(), A[i]) - T.begin();
        B[i] += 1;
    }

    // 答えを空白区切りで出力
    for (int  i = 1; i <= N; i++) {
        if (i >= 2) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}