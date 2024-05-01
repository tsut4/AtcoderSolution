#include <iostream>
using namespace std;

int N, T[1509][1509];
int A[100009], B[100009], C[100009], D[100009];

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // 各紙について +1/-1を加算
    for (int i = 0; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) T[i][j] = 0;
    }
    for (int i = 1; i <= N; i++) {
        // 座標で指示しているからCとDに+１していない。図示すればわかる。
        T[A[i]][B[i]] += 1;
        T[A[i]][D[i]] -= 1;
        T[C[i]][B[i]] -= 1;
        T[C[i]][D[i]] += 1;
    }
    // 二次元累積和をとる
    for (int i = 0; i <= 1500; i++) {
        for (int j = 1; j <= 1500; j++) T[i][j] = T[i][j - 1] + T[i][j];
    }
    for (int i = 1; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) T[i][j] = T[i - 1][j] + T[i][j];
    }

    //面積を答える
    int Answer = 0;
    for (int i = 0; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) {
            if (T[i][j] >= 1) Answer += 1;
        }
    }
    cout << Answer << endl;
    return 0;
}