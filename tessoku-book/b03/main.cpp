#include <iostream>
using namespace std;

int N, A[1009];
bool Answer = false;

int main() {
    //入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int z = 1; z <= N; z++) {
                if (A[x] + A[y] + A[z] == 1000) {
                    //異なる3つを選ぶ必要があるのでx,y,zが同じ場合は除かなければならない。
                    if (x!=y && y!=z && z!= x){ 
                        Answer = true;
                    }
                }
            }
        }
    }

    //出力
    if (Answer == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}