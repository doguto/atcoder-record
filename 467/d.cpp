#include "bits/stdc++.h"
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        long Px, Py;
        long Qx, Qy;
        long Rx, Ry;
        long Sx, Sy;
        cin >> Px >> Py;
        cin >> Qx >> Qy;
        cin >> Rx >> Ry;
        cin >> Sx >> Sy;

        if ((Py - Qy) * (Rx - Sx) != (Ry - Sy) * (Px - Qx)) {
            cout << "Yes" << endl;
            continue;
        }

        if ((Py - Qy) == 0) {
            if (Px + Qx == Rx + Sx) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }

        if ((Px - Qx) == 0) {
            if (Py + Qy == Ry + Sy) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }

        if ((Py + Qy - Ry - Sy) * (Py - Qy) == -((Px + Qx - Rx - Sx) * (Px - Qx))) {
            cout << "Yes" << endl;
            continue;
        }

        cout << "No" << endl;
    }
}
