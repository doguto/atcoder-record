#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    string A;
    cin >> A;

    queue<int> q;
    q.push(X);

    while(!q.empty()) {
        int pos = q.front();
        q.pop();

        if (pos != 0 && A[pos - 1] == '.') {
            A[pos - 1] = '@';
            q.push(pos - 1);
        }
        if (pos != A.size() && A[pos + 1] == '.') {
            A[pos + 1] = '@';
            q.push(pos + 1);
        }
    }

    cout << A << endl;
}
