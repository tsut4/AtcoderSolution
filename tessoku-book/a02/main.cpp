#include <iostream>
using namespace std;

int N, X, A[109];
bool Answer = false;

int main() {
    //入力
    cin >> N >> X;
    for (int i = 1; i <= N; i++) cin >> A[i];

    //全探索
    for (int i = 1; i <= N; i++) {
        if (A[i] == X) Answer = true;
    }

    //出力
    if (Answer == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}