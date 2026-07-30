#include "bits/stdc++.h"
#include <algorithm>
#include <vector>

using namespace std;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(3));
    dp[0] = {0, 0, 0};

    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (i == 1) {
            dp[i] = {a, b, c};
        } else {
            dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
}
