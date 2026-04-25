#include "bits/stdc++.h"

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    for (int h1 = 0; h1 < H; h1++) {
        for (int h2 = h1; h2 < H; h2++) {
            for (int w1 = 0; w1 < W; w1++) {
                for (int w2 = w1; w2 < W; w2++) {
                    bool ok = true;

                    // cout << " (h1,h2,w1,w2) = " << h1 << "," << h2 << "," << w1 << "," << w2 << endl;
                    for (int i = h1; i <= h2; i++) {
                        for (int j = w1; j <= w2; j++) {
                            // cout << "  (i,j) = " << i << "," << j << endl;
                            if (grid[i][j] == grid[h1 + h2 - i][w1 + w2 - j]) continue;

                            // cout << "!!NO!!" << endl;
                            ok = false;
                            break;
                        }
                        if (!ok) break;
                    }
                    if (!ok) continue;

                    count++;
                }
            }
        }
    }

    cout << count << endl;
}
