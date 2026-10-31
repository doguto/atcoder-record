#include "bits/stdc++.h"

using namespace std;

int main() {
    vector<vector<bool>> sign(5, vector<bool>(5));

    for (int i = 0; i < 5; i++) {
        string S;
        cin >> S;

        for (int j = 0; j < 5; j++) {
            char c = S[j];
            sign[i][j] = c == 'o';
        }
    }

    int result = 6;
    for (int i = 0; i < 5; i++) {
        int tmp = 0;
        for (int j = 0; j < 5; j++) {
            if (!sign[i][j]) tmp++;
        }

        result = min(result, tmp);
    }
    
    for (int i = 0; i < 5; i++) {
        int tmp = 0;
        for (int j = 0; j < 5; j++) {
            if (!sign[j][i]) tmp++;
        }

        result = min(result, tmp);
    }

    int tmp = 0;
    for (int i = 0; i < 5; i++) {
        if (!sign[i][i]) tmp++;
    }
    result = min(result, tmp);

    
    tmp = 0;
    for (int i = 0; i < 5; i++) {
        if (!sign[i][4-i]) tmp++;
    }
    result = min(result, tmp);

    cout << result << endl;
}
