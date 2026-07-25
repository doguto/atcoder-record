#include "bits/stdc++.h"
#include <stack>

using namespace std;

int main() {
    int M, D;
    cin >> M >> D;

    string S;
    cin >> S;

    int result = 0;
    stack<bool> a;
    int pre = 0;

    for (int i = 0; i < M; i++) {
        char c = S[i];
        if (c == '.') {
            if (pre > 0) {
                a.push(true);
                pre--;
            } else {
                a.push(false);
            }
        } else {
            int count = min(D, (int)a.size());
            pre = D;

            for (int j = 0; j < count; j++) {
                a.pop();
            }
            for (int j = 0; j < count; j++) {
                a.push(true);
            }

            a.push(true);
        }
    }

    for (int i = 0; i < M; i++) {
        if (!a.top()) result++;
        a.pop();
    }

    cout << result << endl;
}
