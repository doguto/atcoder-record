#include "bits/stdc++.h"

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    // 有向グラフ
    vector<vector<int>> trades(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        trades[A].push_back(B);
    }

    vector<bool> visited(N + 1);
    visited[1] = true;
    int count = 1;

    auto dfs = [&](auto&& self, int i) -> void {
        visited[i] = true;

        count++;
        vector<int> candidates = trades[i];
        for(auto candidate : candidates) {
            if (visited[candidate]) continue;

            self(self, candidate);
        }
    };

    const int initial_item = 1;

    dfs(dfs, initial_item);

    cout << count - 1 << endl;
}
