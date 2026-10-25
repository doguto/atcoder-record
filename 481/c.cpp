#include "bits/stdc++.h"

using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<string, int> kouza;
    
    int nextId = 1;
    for (int i = 0; i < Q; i++) {
        string S;
        cin >> S;

        if (kouza.find(S) != kouza.end()) {
            cout << kouza[S] << endl;
        } else {
            cout << nextId << endl;
            kouza[S] = nextId;
            nextId++;
        }
    }
}
