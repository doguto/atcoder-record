#include "bits/stdc++.h"
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N);
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        int back = min(i, K);
        for (int j = 1; j <= back; j++) {
            if (j == 1) {
                dp[i] = dp[i - j] + abs(h[i] - h[i - j]);
            } else {
                dp[i] = min(dp[i - j] + abs(h[i] - h[i - j]), dp[i]);
            }
        }
    }

    cout << dp[N - 1] << endl;
}
