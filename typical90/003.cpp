#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> loads(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        loads[i] = {A, B};
    }

    // 問題の分割
    // 1. 都市xが同じ道を通らずに帰ってくるための道の本数の最小値
    // 2. どのxを選んだ際にスコアが最大になるか
    // 3. どの都市u,vを選んだ際にスコアが最大になるか
    
}
