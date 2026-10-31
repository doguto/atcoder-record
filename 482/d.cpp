#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> X;
    for (int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        X.push_back(tmp);
    }

    for (int k = 0; k < N; k++) {
        if (k == 0 || k == N - 1) {
            cout << (X[N - 1] - X[0]) / 2 << endl;
            continue;
        }

        // 右に行く場合
        long long t1 = 0;
        t1 += (X[k + 1] - X[k]) / 2;
        t1 += max((X[N - 1] - t1 - X[k + 1] + t1) / 2, (X[k] - X[0]) / 2);

        // 左に行く場合
        long long t2 = 0;
        t2 += (X[k] - X[k - 1]) / 2;
        t2 += max((X[k - 1] - t2 - X[0] + t2) / 2, (X[N - 1] - X[k]) / 2);

        cout << min(t1, t2) << endl;
    }
}
