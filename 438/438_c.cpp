#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = 1;
    for (int i = 1; i < A.size(); i++) {
        if (A[i - count] != A[i]) {
            count = 1;
            continue;
        }

        count++;
        if (count != 4) continue;

        count = 1;
        for (int j = 0; j < 4; j++) {
            A.erase(A.begin() + i - 3);
        }

        if (A.size() < 4) break;
        i = 0;
    }

    cout << A.size();
}
