#include "bits/stdc++.h"

using namespace std;

// 辞書順最小を求める
// -> 貪欲法
// -> 2要素のみならbitも有効

int main() {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    // 貪欲法
    // a,b,c, ... と理論上小さい物から順に文字を探していく
    // 残ったものは削除

    string result;
    int boarder = 0;

    for (int i = 0; i < K; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            bool found = false;
            for (int k = boarder; k < N - (K - i - 1); k++) {
                if (S[k] != c) continue;
                result += S[k];
                boarder = k + 1;
                found = true;
                break;
            }
            if (found) break;
        }
    }

    cout << result << endl;
}
