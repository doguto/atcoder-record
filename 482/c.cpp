#include "bits/stdc++.h"

using namespace std;

int main() {
    long long H, W, N, Q;
    cin >> H >> W >> N >> Q;
    vector<pair<long long, long long>> ichi;
    vector<pair<long long, long long>> ichi_rev;

    for (int i = 0; i < N; i++) {
        long long R, C;
        cin >> R >> C;

        ichi.push_back({R, C});
        ichi_rev.push_back({C, R});
    }
    ichi.push_back({H + 1, W + 1});
    ichi.push_back({H + 1, W + 1});
    ichi_rev.push_back({W + 1, H + 1});
    ichi_rev.push_back({W + 1, H + 1});

    sort(ichi.begin(), ichi.end());
    sort(ichi_rev.begin(), ichi_rev.end());

    for (int i = 0; i < Q; i++) {
        int id;
        cin >> id;

        if (id == 1) {
            long long u, d;
            cin >> u >> d;

            int u_index = lower_bound(ichi.begin(), ichi.end(), make_pair(u, (long long)0)) - ichi.begin();
            int d_index = upper_bound(ichi.begin(), ichi.end(), make_pair(d, W)) - ichi.begin();

            // cout << "u,d = " << u_index << "," << d_index << endl;

            cout << d_index - u_index << endl;
            continue;
        }

        if (id == 2) {
            long long l, r;
            cin >> l >> r;

            int l_index = lower_bound(ichi_rev.begin(), ichi_rev.end(), make_pair(l, (long long)0)) - ichi_rev.begin();
            int r_index = upper_bound(ichi_rev.begin(), ichi_rev.end(), make_pair(r, H)) - ichi_rev.begin();

            // cout << "l,r = " << l_index << "," << r_index << endl;

            cout << r_index - l_index << endl;
        }
    }
}
