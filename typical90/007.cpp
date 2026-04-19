#include "bits/stdc++.h"

using namespace std;

// N: 3*10^5
// Q: 3*10^5
// O(N*Q) はアウト

// 問題の分割
// 1. 最も近いA_iの探索
// 2. Q人のループ

// O(Q)は変えようが無いので、探索部分をlogにする
// => ソートして、2分探索

int main() {
    int N;
    cin >> N;

    vector<int> A(N);    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // O(NlogN)
    sort(A.begin(), A.end());

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int B;
        cin >> B;

        auto index = lower_bound(A.begin(), A.end(), B) - A.begin();
        if (A[index] == B) {
            cout << 0 << endl;
            continue;
        }
        if (index == 0) {
            cout << A[index] - B << endl;
            continue;
        }

        int next = A[index - 1];
        cout << min(abs(A[index] - B), abs(next - B)) << endl;
    }
}
