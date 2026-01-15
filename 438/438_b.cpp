#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string s, t;
    cin >> s;
    cin >> t;

    vector<int> S(N);
    vector<int> T(M);

    for (int i = 0; i < N; i++) {
        S[i] = ((int)s[i] - (int)'0');
    }
    for (int j = 0; j < M; j++) {
        T[j] = ((int)t[j] - (int)'0');
    }

    int result = -1;
    for (int i = 0; i < N - M  + 1; i++) {
        int sum = 0;
        bool isNext = false;

        for (int j = 0; j < M; j++) {
            sum += (10 + S[i + j] - T[j]) % 10;

            if (result != -1 && sum >= result) {
                isNext = true;
                break;
            }
        }

        if (isNext) continue;
        result = sum;
    }

    cout << result << endl;
}
