#include "bits/stdc++.h"
using namespace std;

int main() {
    int Q;
    cin >> Q;

    stack<string> books;

    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            string book;
            cin >> book;

            books.push(book);
        } else if (query == 2) {
            string book = books.top();
            cout << book << endl;
        } else if (query == 3) {
            books.pop();
        }
    }
}
