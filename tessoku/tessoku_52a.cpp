#include "bits/stdc++.h"
using namespace std;

int main() {
    int Q;
    cin >> Q;

    queue<string> people;

    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            string name;
            cin >> name;
            people.push(name);
        } else if (query == 2) {
            string name = people.front();
            cout << name << endl;
        } else if (query == 3) {
            people.pop();
        }
    }
}
