#include "bits/stdc++.h"
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> map(N);

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            map[a - 1].push_back(i);
        }
    }

    for (int i = 0;i < N; i++) {
        cout << map[i].size() << " ";
        for (int j = 0; j < map[i].size(); j++) {
            cout << map[i][j] + 1;
            if (j != map[i].size() - 1) cout << " ";
        }
        cout << endl;
    }
}
