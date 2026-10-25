#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;

    // Star -> Star List
    vector<vector<int>> roads(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        roads[A].push_back(B);
    }

    for (int i = 1; i < N + 1; i++) {
        sort(roads[i].begin(), roads[i].end());
    }

    vector<int> visited(N + 1, false);
    visited[S] = true;

    // Startからのコスト, 位置
    priority_queue<pair<int, int>> kueue;
    int size = roads[S].size();
    for (int i = 0; i < size; i++) {
        kueue.push({(i != 0), roads[S][i]});
    }

    while(true) {
        if (kueue.size() == 0) {
            cout << -1 << endl;
            break;
        }

        auto pos = kueue.top();
        kueue.pop();
        visited[pos.second] = true;

        if (pos.second == T) {
            cout << pos.first << endl;
            break;
        }

        int ssize = roads[pos.second].size();
        for (int i = 0; i < ssize; i++) {
            if (visited[roads[pos.second][i]]) continue;

            int cost = pos.first + (i != 0);
            kueue.push({cost, roads[pos.second][i]});
        }
    }
}
