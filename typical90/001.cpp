#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, L, K;
    cin >> N >> L >> K;

    vector<int> piece_lengths(N+1);
    for (int i = 0; i < N; i++) {
        cin >> piece_lengths[i];
    }
    piece_lengths[N] = L;

    // 問題を分割する
    // 1. Kに対し、スコアをx以上にすることが出来るか
    // 2. xの最大値は何か

    // 副題1
    // Greedy法で解く
    // 左から切っていく訳なので、単純に左から長さがx以上になったら切断を繰り返す
    // これを繰り返してK+1個に分割出来ればok
    // 計算量: O(N)

    auto canSplit = [](int minLength, int N, int K, vector<int> A) {
        int score = 0;
        int count = 1;
        bool can = false;
        int lastI = 0;
        for (int i = 0; i < N; i++) {
          int add = (i == 0)? A[i] : A[i] - A[i-1];
          score += add;
          // cout << "score: " << score << endl;
          if (score >= minLength) {
            count++;
            if (count >= K + 1) {
              can = true;
              lastI = i;
              break;
            };
            
            score = 0;
            continue;
          }
        }
        if (!can) return false;
        if (A[N] - A[lastI] >= minLength) return true;
        return false;
    };



    // 副題2
    // 方法は色々と考えられる
    // (1) 全探索
    // (2) 二分探索
    // よってまずは計算量的な制限を考える
    // N <= 10^5 なので、N^2 > 10^9 より、O(N^2) は不可
    // よって(1)はTLEとなるため、(2)を採用する


    // K > 0 より、0 < x < L
    int left = 0;
    int right = L;
    int middle;

    while(true) {
        if (right - left <= 1) break;
        middle = (left + right) / 2;
        if (canSplit(middle, N, K, piece_lengths)) {
          left = middle;
        } else {
          right = middle;
        }
        
        // corut << left << " - " << right << endl;
    }
    
    cout << left << endl;
}
