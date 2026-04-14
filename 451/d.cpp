#include "bits/stdc++.h"

using namespace std;

int calcurateKeta(int number) {
    int keta;
    int tmp = number;
    while (tmp != 0) {
        int tmp = tmp / 10;
        keta++;
    }

    return keta;
}

vector<int> getTmpGoodNumbers(int size) {

}

int main() {
    vector<vector<int>> binaries(9);
    int index = 1;
    while (true) {
        int binary = pow(2, index);
        int keta = calcurateKeta(binary);
        binaries[keta - 1].push_back(binary);
        index++;

        if (binary > 1000000000) break;
    }

    // 各桁の良い数字を一旦出す
    vector<set<int>> good_numbers;

    // 最大9桁
    // 各桁の数字に対して、どの桁を構成用途するかを全部出す
    // 1 -> 1
    // 2 -> 1,1 2 的な
    // 9 -> 8,1 7,2 6,3 5,4
    for (int i = 1; i < 9; i++) {
        for (int j = 0; j < binaries[i].size(); j++) {
            good_numbers[i].insert(binaries[i][j]);
        }

        int mid = i / 2;
        if (mid == 0) continue;

        for (int k = 1; k < mid; k++) {
            
        }
    }
}


/**
 * 1,
 * 2,
 * 4,
 * 8,
 * 11,12,14,16,
 * 18,21,22,24,28,32,
 * 41,42,44,48,64
 * 
 */

/**
 * 
 */


// X_k = p + (X_k-1 & 1ケタ) + (X_k-2 & 2ケタ)
