#include "bits/stdc++.h"

using namespace std;

// 1. A == B に出来るか？
// 2. T回ループ

// 1≤T≤3×10^5
// 1≤A,B≤2×10^6

// -> O(T × log(A)) とかにしないといけない


// 1
// xx と (xx) 以外は置換不可能
// 一回全て xx 系に落として置換できれば良い

// B のxのレイヤーを分ける

string resolve(string A) {
    deque<char> resolved;

    for (int j = 0; j < A.size(); j++) {
        char a = A[j];

        if (a == 'x') {
            resolved.push_back(a);
            continue;
        }

        if (a == '(') {
            resolved.push_back(a);
            continue;
        }

        if (a == ')') {
            vector<char> xes(2);
            bool can_delete = true;

            if (resolved.size() < 3) {
                resolved.push_back(a);
                continue;
            }

            for (int k = 0; k < 2; k++) {
                char mid = resolved.back();
                if (mid != 'x') {
                    can_delete = false;
                    break;
                }

                // cout << "   mid: " << mid << endl;
                xes[k] = 'x';
                resolved.pop_back();
            }
            char check_point = resolved.back();

            if (!can_delete || check_point != '(') {
                for (int k = 0; k < xes.size(); k++) {
                    // cout << "   Reverse x: " << xes[k] << endl;
                    resolved.push_back(xes[k]);
                }
                resolved.push_back(a);
                continue;
            }

            resolved.pop_back();
            for (int k = 0; k < 2; k++) {
                // cout << xes[k] << endl;
                resolved.push_back(xes[k]);
            }
        }
    }

    string result;
    int n = resolved.size();
    // cout << "   n: " << n << endl;

    for (int i = 0; !resolved.empty(); i++) {
        result += resolved.front();

        // cout << "   " << result << endl;

        resolved.pop_front();
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string A, B;
        cin >> A >> B;

        A = resolve(A);
        B = resolve(B);

        // cout << "   A: " << A << ", B: " << B << endl;

        if (A == B) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
