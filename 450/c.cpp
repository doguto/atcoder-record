#include "bits/stdc++.h"

using namespace std;

bool isInvalid(int grid, set<int> invalidGroup) {
    if (grid == -2) return true;
    auto iterator = invalidGroup.find(grid);
    return iterator != invalidGroup.end();
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> grids(W, vector<int>(H));
    set<int> invalidGroup;
    int count = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char state;
            cin >> state;
            if (state == '#') {
                grids[j][i] = -1;
                continue;
            }

            // こっから下は白

            if (i == 0 || j == 0) {
                grids[j][i] = -2;
                continue;
            }

            if (i == H - 1 || j == W - 1) {
                grids[j][i] = -2;
                if (!isInvalid(grids[j-1][i], invalidGroup)) invalidGroup.insert(grids[j-1][i]);
                if (!isInvalid(grids[j][i-1], invalidGroup)) invalidGroup.insert(grids[j][i-1]);
                continue;
            }

            int upperGrid = grids[j][i - 1];
            int leftGrid = grids[j - 1][i];
            if (upperGrid == -1 && leftGrid == -1) {
                count++;
                grids[j][i] = count;
                continue;
            }
            if (upperGrid == -1) {
                if (isInvalid(leftGrid, invalidGroup)) {
                    grids[j][i] = -2;
                    continue;
                }
                grids[j][i] = leftGrid;
                continue;
            }
            if (leftGrid == -1) {
                if (isInvalid(upperGrid, invalidGroup)) {
                    grids[j][i] = -2;
                    continue;
                }
                grids[j][i] = upperGrid;
                continue;
            }

            if (isInvalid(upperGrid, invalidGroup) || isInvalid(leftGrid, invalidGroup)) {
                if(leftGrid != -2) invalidGroup.insert(leftGrid);
                if(upperGrid != -2) invalidGroup.insert(upperGrid);
                grids[j][i] = -2;
                continue;
            }

            grids[j][i] = leftGrid;
            if (upperGrid != leftGrid) count--;
        }
    }

    cout << count - invalidGroup.size();
}
