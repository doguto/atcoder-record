#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << N - i;
        if (i != N-1) cout << ',';
    }
}
