#include "bits/stdc++.h"

using namespace std;

// 二種類の文字等のソート問題
// -> bit探索

int main() {
    int N;
    cin >> N;
    if (N % 2 == 1) return 0;

    // 情報の整理
    // 1 <= N <= 20  -> O(N^6)くらいまでは余裕
    // あり得る要素数
    // 大きくても、2^20 概ね 10^6

    // 問題を分割する
    // 1. ()の文字列の辞書順ソート
    // 2. ()の文字列が整合かどうか
    // 3. 探索法

    // 副題1
    // (: 0, ): 1 とし、bit対応させる. こうすれば単純に小さい順に並べれば辞書順となる
    // 計算量: 副題3のループ時にそもそも小さい順でやれば良いので、O(0)

    // 副題2
    // 文字列を左から見ていき、出てきた ')' の数が '(' を越さなければok
    // また最後に等しくなればok
    // 計算量: O(N)

    auto isValid = [](const string text) -> bool {
        int count = 0;
        for(auto s : text) {
            if (s == '(') count++;
            else if (s == ')') count--;

            if (count < 0) return false;
        }

        return (count == 0);
    };

    // 副題3
    // 上記副題2から整合性は判定できる
    // よってあり得るものをループで回し、整合性のものだけ取得 -> 副題1でソートとすればよい
    // 今回計算量はかなり余裕なので、O(2^N)で全探索して問題ない

    // 計算量: O(N * 2^N)

    // (1<<N) つまり 0b100...000 が最大値
    for (int bit = 0; bit < (1<<N); bit++) {
        string text;
        for (int i = N - 1; i >= 0; i--) {
            if (!(bit & (1<<i))) text += "(";
            else text += ")";
        }

        if (isValid(text)) {
            cout << text << endl;
        }
    }
}
