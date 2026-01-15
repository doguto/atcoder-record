#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<int, vector<int>> map;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 二分探索 return true
    binary_search(A.begin(), A.end(), 1);

    // 二分探索 return index
    sort(A.begin(), A.end());
    upper_bound(A.begin(), A.end(), 1);

    // 順列探索
    do {
        for(auto a : A) {
            cout << a << ", ";
        }
        cout << endl;
    } while (next_permutation(A.begin(), A.end()));
    

    int index = 0;

    priority_queue<int> puepue;

    map[0].push_back(-1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (map[index].back() != A[i]) {
            index++;
        }
        map[index].push_back(A[i]);
        if (map[index].size() < 4) continue;

        map[index].resize(0);
        index--;
    }

    int sum = 0;
    for (auto& [key, vec] : map) {
        sum += vec.size();
    }
    cout << sum - 1 << endl;
}
