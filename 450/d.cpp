#include "bits/stdc++.h"

using namespace std;

// 2×10^5 => 10^8 いくとグレーだよ～
// O^2 はダメ
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        tmp %= K;
        A[i] = tmp;
    }

    // 小さい順にする
    sort(A.begin(), A.end());

    int max = A[N - 1];
    int min = A[0];
    int result = max - min;
    
    for (int i = 0; i < N - 1; i++) {
        A[i] += K;
        max = A[0 + i];
        min = A[1 + i];
        result = std::min(result, max - min);
    }
    cout << result << endl;
}
