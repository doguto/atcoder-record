#include "bits/stdc++.h"
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grids(H, vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grids[i][j];
        }
    }

    // '.' && 見たことがある => true
    // 左上から順に順次に見ていくときのフラグ
    // これで結果をcacheしているから、O(HW)で済む
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // 隣接成分を奥まで探索する必要があるよ
    // 深さ優先探索の再帰関数
    auto isByWallGroup = [&](auto&& self, int x, int y, bool byWall) -> bool {
        if (grids[x][y] == '#') return false;
        visited[x][y] = true;

        bool byWallSelf = x == 0 || x == H - 1 || y == 0 || y == W - 1;
        bool byWallGroup = byWall || byWallSelf;

        if (x != 0 && !visited[x - 1][y]) byWallGroup |= self(self, x - 1, y, byWallGroup);
        if (x != H - 1 && !visited[x + 1][y]) byWallGroup |= self(self, x + 1, y, byWallGroup);
        if (y != 0 && !visited[x][y - 1]) byWallGroup |= self(self, x, y - 1, byWallGroup);
        if (y != W - 1 && !visited[x][y + 1]) byWallGroup |= self(self, x, y + 1, byWallGroup);

        return byWallGroup;
    };

    int count = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grids[i][j] != '.') continue;
            if (visited[i][j]) continue;

            if (isByWallGroup(isByWallGroup, i, j, false)) continue;
            count++;
        }
    }

    cout << count << endl;
}
