#include "bits/stdc++.h"

using namespace std;

int main() {
    string S;
    cin >> S;
    string out;

    for (auto c : S) {
        if (c >= '0' && c <= '9') {
            out.push_back(c);
        }
    }
    cout << out << endl;
}
