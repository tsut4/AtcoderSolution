#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int N, Q;
    int A[100009], X[100009];
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++) cin >> X[i];

    // Aをsortして小さい順に並び替える
    sort(A + 1, A + N + 1);

    // 質問に答える
    for (int i = 1; i <= Q; i++) {
        int pos = lower_bound(A + 1, A + N + 1, X[i]) - A; 
        // pos = lower_bound(A + 1, A + N + 1, X[i]) - Aでは、配列Aの中でX[i]より大きいか等しい要素の位置を返す。
        // Xの値がA[R[i] - 1]よりも大きい場合はR[i]が記録される。 
        cout << pos - 1 << endl; 
        // pos - 1 をすることで、X[i]よりも小さい要素数が出力される。
    }
    return 0;
}
