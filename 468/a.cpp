#include "bits/stdc++.h"
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int result = 0;
    vector<int> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];

        if (i < 2) continue;

        if (A[i - 2] < A[i - 1] && A[i - 1] > A[i]) {
            result++;
        }
    }

    cout << result << endl;
}
