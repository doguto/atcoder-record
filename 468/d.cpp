#include "bits/stdc++.h"
#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;

    int len = S.size();
    if (len == 1) {
        cout << 1 << endl;
        return 0;
    } else if (len == 2) {
        cout << 3 << endl;
        return 0;
    }

    int result = 0;

    // odd
    for (int i = 0; i < len; i++) {
        int diff = 0;
        for (int j = 0; ; j++) {
            if (i - j < 0 || i + j >= len) break;
            if (j == 0) {
                result++;
                continue;
            }

            if (S[i - j] == S[i + j]) {
                result++;
            } else {
                if (diff == 1) break;
                result++;
                diff++;
                continue;
            }
        }
    }

    // even
    for (int i = 0; i < len - 1; i++) {
        int diff = 0;
        for (int j = 0; ; j++) {
            if (i - j < 0 || i + 1 + j >= len) break;
            if (j == 0) {
                result++;
                if (S[i] != S[i + 1]) diff++;
                continue;
            }

            if (S[i - j] == S[i + 1 + j]) {
                result++;
            } else {
                if (diff == 1) break;
                result++;
                diff++;
                continue;
            }
        }
    }

    cout << result << endl;
}
