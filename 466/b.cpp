#include "bits/stdc++.h"
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> max_color(M, -1);
    for (int i = 0; i < N; i++) {
        int c, s;
        cin >> c >> s;
        max_color[c - 1] = max(s, max_color[c - 1]);
    }

    for (int i = 0; i < M; i++) {
        cout << max_color[i];
        if (i != M - 1) cout << " ";
    }
    cout << endl;
}
