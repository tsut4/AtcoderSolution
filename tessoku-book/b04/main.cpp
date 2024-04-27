#include <iostream>
#include <string>
using namespace std;

int main() {
	// 入力
	string N;
	cin >> N;
	
	// 答えを求める
	int Answer = 0;
    // 配列や文字列のsize()で帰ってくる要素数の値はsize_tという符号なしの整数型である。
    // C++(GCC9.2.1)においてsize_tはunsigined long(単なる別名)として定義されている。
	// 実行環境によって、for分でfor (int i = 1; i < 配列.size(); i++)と書いたときに警告が出るのは、
    // int型(符号付き)とsize_t型(型無し)を比較しているからである。(暗黙的にキャストが行われるので動作に影響はない。)
    
    for (int i = 0; i < (int)N.size(); i++) { // size()の結果を符号付きにキャストすれば問題ない。
		int keta = 0; // 初期化してやらないとコンパイルエラー([-Wmaybe-uninitialized])が発生する。
		int kurai = (1 << (N.size() - 1 - i));
		if (N[i] == '0') keta = 0;
		if (N[i] == '1') keta = 1;
		Answer += keta * kurai;
	}
	
	// 出力
	cout << Answer << endl;
	return 0;
}