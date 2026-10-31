#include "bits/stdc++.h"

using namespace std;

int main() {
    string S;
    cin >> S;

    int count = 0;
    for (auto c : S) {
        if (c == 'o') count++;
    }

    string result;
    if (count % 2 == 0) result = "even";
    else result = "odd";
    cout << result << endl;
}
