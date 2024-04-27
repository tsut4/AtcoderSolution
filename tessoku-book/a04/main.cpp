#include <iostream>
using namespace std;

int main() {
    // 入力
    int N;
    cin >> N;

    for (int x = 9; x >= 0; x--) {
        int wari = (1 << x); // xの2乗
        cout << (N / wari) % 2;
    }
    cout << endl;
    return 0;
}