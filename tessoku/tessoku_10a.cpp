#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, D;
    cin >> N;

    vector<int> A(N);
    vector<int> leftMax(N);
    vector<int> rightMax(N);

    cin >> A[0];
    leftMax[0] = A[0];
    for (int i = 1; i < N; i++) {
        cin >> A[i];
        leftMax[i] = max(leftMax[i - 1], A[i]);
    }
    rightMax[N - 1] = A[N - 1];
    for (int i = 1; i < N; i++) {
        rightMax[N - 1 - i] = max(rightMax[N - i], A[N - 1 - i]);
    }

    cin >> D;

    for (int i = 0; i < D; i++) {
        int L, R;
        cin >> L >> R;

        int maxSize = max(leftMax[L - 2], rightMax[R]);
        cout << maxSize << endl;
    }
}
