#include "bits/stdc++.h"

using namespace std;

// 2^N => Dynamic Planning

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    const string target = "atcoder";
    const int target_length = 7;

    // 現在Sのi文字目まで確認し、その内j個を取り出して一致しているパターンの数をdp[i][j]とする

    // attcoder

    //    j
    // i  0 1 2 3 4 5 6 7
    // 0  1 0 0 0 0 0 0 0
    // 1  1 1 0 0 0 0 0 0 // [1,1] = 1 なのは、S[0] == 'a'なため
    // 2  1 1 1 0 0 0 0 0
    // 3  1 1 2 0 0 0 0 0
    // 4  1 1 2 2 0 0 0 0
    // 5
    // 6
    // 7
    // 8
    // .
    // .

    vector<vector<int>> dp(N + 1, vector<int>(target_length + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
        // cout << dp[i][0] << " ";
        for (int j = 1; j <= target_length; j++) {
            if (i == 0) {
                dp[i][j] = 0;
                // cout << dp[i][j] << " ";
                continue;
            }

            dp[i][j] = dp[i - 1][j];

            if (S[i - 1] == target[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1];
                if (dp[i][j] > 1000000007) {
                    dp[i][j] = dp[i][j] % 1000000007;
                }
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    cout << dp[N][target_length] << endl;
}
