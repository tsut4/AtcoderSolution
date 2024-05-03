#include <iostream>
using namespace std;

int N;
long long K, A[100009];

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        auto it = lower_bound(A + 1, A + N + 1, A[i] + K + 1) - A;
        sum += it - 1 - i;
    }
    cout << sum << endl;
    return 0;
}