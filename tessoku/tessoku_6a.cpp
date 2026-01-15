#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            a[i] = tmp;
            continue;
        }

        a[i] = a[i - 1] + tmp;
    }

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;

        if (L == 1) {
            cout << a[R - 1] << endl;
            continue;
        }
        cout << a[R - 1] - a[L - 2] << endl;
    }
}
