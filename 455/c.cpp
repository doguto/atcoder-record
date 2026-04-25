#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // 1. xの選び方
    // 2. xの数のiを消す
    // 3. 最小値を求める

    // - あり得るx * K を全通り行い、その最小値を出す
    //      nCk = n * (n - 1) * ... * (n - k + 1)
    // NONONONONO
    
    // - そのxを消すのが最大となるようなxを一意に出せるようなデータ構造を取っておく
    // x の map

    long long sum = 0;
    map<long, long long> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sum += a;

        A[a] += a;
    }

    vector<long long> Avector;
    for (auto& p : A) {
        Avector.push_back(p.second);
    }

    if (Avector.size() <= K) {
        cout << 0 << endl;
        return 0;
    }

    sort(Avector.rbegin(), Avector.rend());

    for (int i = 0; i < K; i++) {
        sum -= Avector[i];
    }

    cout << sum << endl;
}
