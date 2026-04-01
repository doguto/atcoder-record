#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> costs(N + 1, vector<int>(N + 1));

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int cost;
            cin >> cost;
            costs[i][j] = cost;
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int parentCost = costs[i][j];
            for (int k = i; k <= j; k++) {
                int cost = costs[i][k] + costs[k][j];
                if (cost >= parentCost) continue;

                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}
