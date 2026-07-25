#include "bits/stdc++.h"
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    long coef = 1;
    for (int i = N - 1; i > 0; i--) {
        coef *= i;
    }

    vector<int> P(N);
    vector<int> Q(N);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }

    int pcount = 0;
    int qcount = 0;
    vector<int> used;
    long pcoef = coef;
    for (int i = 0; i < N; i++) {
        int size = used.size();
        int under = 0;
        for (int j = 0; j < size; j++) {
            if (P[i] > used[j]) under++;
            // cout << "   aa: " << i << ", " << j << endl;
        }

        pcount += (P[i] - 1 - under) * pcoef;
        if (i != N - 1) pcoef /= N - 1 - i;

        used.push_back(P[i]);
    }
    used.clear();
    long qcoef = coef;
    for (int i = 0; i < N; i++) {
        int size = used.size();
        int under = 0;
        for (int j = 0; j < size; j++) {
            if (Q[i] > used[j]) under++;
            // cout << "   bb: " << i << ", " << j << endl;
        }

        qcount += (Q[i] - 1 - under) * qcoef;
        if (i != N - 1) qcoef /= N - 1 - i;

        used.push_back(Q[i]);
    }

    cout << max(qcount - pcount - 1, 0) << endl;
}
