#include "bits/stdc++.h"
#include <ctime>

using namespace std;

// タイムラインにおける人の状態（人数）を持つデータ構造を作成する
//   => 時刻x~x+Dに居る人数
// あり得るxをにおける組み合わせの計算
//   => x ~ x+D までに居る人がm人として、 mC2

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> timeline(1000001);

    for (int i = 0; i < N; i++) {
        int S, T;
        cin >> S >> T;
        // cout << "   S: " << S << ", T: " << T << endl;
        if (T - S < D) continue;

        timeline[S]++;
        timeline[T - D + 1]--;
    }

    long count = 0;
    int sum = 0;
    for (int i = 1; i < 1000001 - D; i++) {
        sum += timeline[i];
        if (sum <= 1) continue;

        count += (sum * sum - 1) / 2;
    }

    cout << count << endl;
}
