#include "bits/stdc++.h"
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> x(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int tmp;
            cin >> tmp;
            if (j == 0) {
                x[i][j] = tmp;
                continue;
            }
            x[i][j] = x[i][j - 1] + tmp;
        }
    }

    int Q;
    cin >> Q;
    vector<int> a(Q);
    vector<int> b(Q);
    vector<int> c(Q);
    vector<int> d(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> d[i];
    }

    for (int i = 0; i < Q; i++) {
        int sum = 0;
        for (int j = a[i] - 1; j < c[i]; j++) {
            if (b[i] == 1) {
                sum += x[j][d[i] - 1];
                continue;
            }
            sum += (x[j][d[i] - 1] - x[j][b[i] - 2]);
        }
        cout << sum << endl;
    }
}
