#include "../bits/stdc++.h"
using namespace std;

int main() {
    int k[5] = {0};
    for (int i = 0; i < 5; i++) {
        cin >> k[i];
    }
    char c[5] = {'A', 'B', 'C', 'D', 'E'};
    vector<int> scores(31);
    vector<string> names(31);
    for (int i = 30; i >= 0; i--) {  // calc score
        int tmp = i + 1;
        for (int j = 4; j >= 0; j--) {
            int b = tmp / pow(2, j);
            tmp %= (int)pow(2, j);
            if (b == 0) continue;
            scores[i] += k[j];
            names[i] += c[j];
        }
    }

    vector<int> sortsc(31);
    vector<string> sortnm(31);
    sortsc[0] = scores[0];
    sortnm[0] = names[0];
    for (int i = 1; i < 31; i++) {  // score sort
        sortsc[i] = scores[i];
        sortnm[i] = names[i];
        if (sortsc[i] <= sortsc[i - 1]) continue;
        
        int index = 0;
        for (int j = 1; true; j++) {
            if (sortsc[i] <= sortsc[i - j]) break;
            index++;
        }
        int tmpsc = sortsc[i];
        string tmpnm = sortnm[i];
        for (int j = i - index; j < i; j++) {
            sortsc[j + 1] = sortsc[j];
            sortnm[j + 1] = sortnm[j];
        }
        sortsc[i - index] = tmpsc;
        sortnm[i - index] = tmpnm;
    }

    for (int i = 1; i < 31; i++) {  // name sort
        if (sortsc[i] < sortsc[i - 1]) continue;

        int index = 0;
        for (int j = 0; true; j++) {
            if (sortsc[i] > sortsc[i + j]) break;
            index++;
        }
        sort(&sortnm[i], &sortnm[i + index], greater<string>());
        i += index;
    }

    for (int i = 0; i < 31; i++) {  // output
        cout << sortnm[i] << endl;
    }
}
