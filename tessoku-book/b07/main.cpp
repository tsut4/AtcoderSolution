#include <iostream>
using namespace std;

int N, T;
int L[500009], R[500009];
int Answer[500009], B[500009];

int main() {
	// 入力
	cin >> T >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 前後1時間の出勤者の比を計算する
	for (int i = 1; i <= N; i++) {
		B[L[i]] += 1;
		B[R[i]] -= 1;
	}
	
	Answer[0] = B[0];
	for (int d = 1; d <= T; d++) Answer[d] = Answer[d - 1] + B[d];
	for (int d = 0; d < T; d++) cout << Answer[d] << endl;
	return 0;
}