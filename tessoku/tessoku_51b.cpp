#include "bits/stdc++.h"
using namespace std;

int main() {
    string S;
    cin >> S;

    stack<int> indexes;
    for (int i = 0; i < S.size(); i++) {
        char symbol = S[i];
        if (symbol == '(') {
            indexes.push(i + 1);
            continue;
        }

        if (symbol == ')') {
            int index = indexes.top();
            indexes.pop();
            cout << index << " " << i + 1 << endl;
        }
    }
}
