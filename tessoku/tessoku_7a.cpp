#include "bits/stdc++.h"
using namespace std;

int main() {
    int D, N;
    cin >> D >> N;

    vector<int> a(D + 1);
    for (int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;

        a[L - 1] += 1;
        a[R] -= 1;
    }

    cout << a[0] << endl;
    int sum = a[0];
    for (int i = 1; i < D; i++) {
        sum += a[i];
        cout << sum << endl;
    }
}
