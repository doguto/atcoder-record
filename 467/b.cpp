#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;

    int actual = 10000;
    int thorical = 10000;
    for (int i = 0; i < N; i++) {
        int A, B;
        string S;
        cin >> A >> B >> S;
        thorical -= A;
        if (S == "keep") {
            actual -= B;
        } else {
            actual -= A;
        }
    }

    cout << thorical - actual << endl;
}
