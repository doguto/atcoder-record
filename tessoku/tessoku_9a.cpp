#include "bits/stdc++.h"
using namespace std;

int main() {
    int H, W;
    int N;
    cin >> H >> W >> N;

    vector<vector<int>> map(H + 1, vector<int>(W + 1));
    for (int i = 0; i < N; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        map[A - 1][B - 1] += 1;
        map[A - 1][D] -= 1;
        map[C][B - 1] -= 1;
        map[C][D] += 1;
    }

    vector<vector<int>> snows(H, vector<int>(W));

    snows[0][0] = map[0][0];
    for (int i = 1; i < W; i++) {
        snows[0][i] = snows[0][i - 1] + map[0][i];
    }

    for (int i = 1; i < H; i++) {
        snows[i][0] = snows[i - 1][0] + map[i][0];

        for (int j = 1; j < W; j++) {
            snows[i][j] = snows[i][j - 1] + snows[i - 1][j] + map[i][j] - snows[i - 1][j - 1];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << snows[i][j] << ' ';
        }
        cout << endl;
    }
}
