#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> clothes(M, false);

    bool q1 = true;
    bool q2 = true;

    for (int i = 0; i < N; i++) {
        int f;
        cin >> f;

        if (clothes[f - 1]) {
            q1 = false;
        }

        clothes[f - 1] = true;
    }

    for (int i = 0; i < M; i++) {
        if (clothes[i]) continue;

        q2 = false;
        break;
    }

    if (q1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    if (q2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
