#include "bits/stdc++.h"
using namespace std;

int main() {
    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<int>> prices;
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            int price;
            cin >> price;
            prices.push(price);
        } else if (query == 2) {
            int price = prices.top();
            cout << price << endl;
        } else if (query == 3) {
            prices.pop();
        }
    }
}
