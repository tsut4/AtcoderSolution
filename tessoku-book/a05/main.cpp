#include <iostream>
using namespace std;

int main () {
    int N, K, Answer = 0;
    cin >> N >> K;

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            int z = K - x - y;
            if (z >= 1 && z <= N) Answer += 1;
        }
    }
    cout << Answer << endl;
    return 0;
}