#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> hen(N + 1);
    vector<int> choten;

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        hen[u].push_back(v);
        hen[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        int c;
        choten.push_back(c);
    }

    int rootId = choten[0];
    vector<bool> visited(N, false);
    vector<vector<int>> depths(N + 1, vector<int>());
    vector<int> max_depths(N + 1);

    int max1 = 0, max2 = 0;

    auto dfs = [&](auto&& self, int chotenId, int depth, int treeId) -> void {
        if (visited[chotenId]) return;
        visited[chotenId] = true;
        depths[treeId][chotenId] = depth;
        max_depths[treeId] = max(max_depths[treeId], depth);

        for (int cId : hen[chotenId + 1]) {
            self(self, cId, depth + 1, treeId);
        }
    };

    visited[0] = true;

    for (int i = 0; i < hen[0].size(); i++) {
        dfs(dfs, hen[0][i], 1, i);
    }

    for (auto d : max_depths) {
        if (d >= max1) {
            max2 = max1;
            max1 = d;
        } else if (d >= max2) {
            max2 = d;
        }
    }
}
