#include "bits/stdc++.h"

using namespace std;

// N <= 5*10^3
// => O(N^2 * logN) くらいまではok

struct Quest
{
    int D;
    int C;
    int S;

    // sort関数を扱うため、< operatorを作成
    bool operator<(const Quest& other) const {
        if (D != other.D) return D < other.D;
        if (C != other.C) return C < other.C;
        return S < other.S;
    }
};

int main() {
    int N;
    cin >> N;

    vector<Quest> Quests(N);
    int limit = 0;

    for (int i = 0; i < N; i++) {
        int D, C, S;
        Quests[i] = {D, C, S};
        limit = max(limit, D);
    }

    sort(Quests.begin(), Quests.end());

    // i日目にj個のタスクが完了しているときの報酬合計をdp[i][j]とする

    //   j
    // i  0  1  2  3  4  5  6
    // 0  0  0  0  0  0  0  0
    // 1  0 10  0  0  0  0  0
    // 2  0 10
    // 3
    // 4



    vector<vector<int>> dp(N + 1, vector<int>(limit + 1, 0));

    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < limit + 1; j++) {

        }
    }
}
