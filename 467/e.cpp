#include "bits/stdc++.h"
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(N - 1);

    vector<int> diffs(N - 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int diff = B[i] - ((A[i] + A[i + 1]) % M);
        if (diff < 0) diff += M;
        diffs[i] = diff;
    }
}
