#include "bits/stdc++.h"

using namespace std;

int main() {
    int Q;
    cin >> Q;

    // 昇順にする
    priority_queue<int, vector<int>, greater<int>> trees;

    for (int i = 0; i < Q; i++) {
        int q, h;
        cin >> q >> h;

        if (q == 1) {
            trees.push(h);
        } else if (q == 2) {
            while (!trees.empty() && trees.top() <= h) {
                trees.pop();
            }
        }

        cout << trees.size() << endl;
    }
}
