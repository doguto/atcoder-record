#include "bits/stdc++.h"

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    stack<pair<int, int>> coods;

    int bar = 0;
    for (int i = 0; i < M; i++) {
        int R, C;
        cin >> R >> C;

        pair<int, int> a;
        a.first = R;
        a.second = C;
        coods.push(a);
    }

    int sum = 0;
    int b = 0;


    vector<bool> colomns(N, true);
    vector<bool> records(N, true);
    for (int i = 0; i < M; i++) {
        auto c = coods.top();
        coods.pop();

        if (colomns[c.second - 1] && records[c.first]) {
            sum++;
        }

        if (colomns[c.second - 1]) b++;
        if (records[c.first]) b++;

        colomns[c.second - 1] = false;
        records[c.first] = false;

        if (b >= 2 * N) break;
    }

    cout << sum << endl;
}
