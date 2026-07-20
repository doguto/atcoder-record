#include "bits/stdc++.h"
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(N - 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    int last_pose = -1;
    vector<int> distances;
    for (int i = 0; i < N - 1; i++) {
        if ((A[i] + A[i + 1]) % 2 == B[i]) continue;


        // cout << "   " << i << ": " << i - last_pose << endl;
        distances.push_back(i - last_pose);
        last_pose = i;
    }
    distances.push_back(N - last_pose);
    // cout << "   " << N - 1 - last_pose << endl;

    int a = 0;
    int b = 0;
    for (int i; i < distances.size(); i++) {
        if (i % 2 == 0) a += distances[i];
        else b += distances[i];
    }

    cout << min(a, b) << endl;
}
