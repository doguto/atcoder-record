#include "bits/stdc++.h"
using namespace std;

int main() {
    int D, F;
    cin >> D >> F;

    int a = (D - F) % 7;
    cout << 7 - a << endl;
}
