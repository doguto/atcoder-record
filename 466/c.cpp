#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

//

int main() {
    int N;
    cin >> N;

    int count = 0;
    int q = 2;
    for (int i = 1; i <= N - 1; i++) {
        count += max(q - 1 - i, 0);

        q = max(i + 1, q);
        while (true) {
            if (q > N) break;
            cout << "? " << i << " " << q << endl;
            string s;
            cin >> s;
            if (s == "Yes") {
                count++;
                q++;
            } else {
                break;
            }
        }
    }

    cout << "! " << count << endl;
}
