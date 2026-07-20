#include "bits/stdc++.h"

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    if (W * 10000 >= 25.0 * H * H) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
