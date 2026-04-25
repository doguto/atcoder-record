#include "bits/stdc++.h"

using namespace std;

struct Card {
    int value;
    int mount;
    Card* base;
    Card* next;
};

int main() {
    int N, Q;
    cin >> N >> Q;

    // 1. C_i の積まれている山の検索
    // 2. C_i の上に積まれているカード軍の検索
    // 3. P_i の積まれている山の検索
    // 4. C_i たちの更新

    vector<Card> cards(N);
    vector<Card> mounts(N);

    for (int i = 0; i < N; i++) {
        mounts[i] = {-i, -1, nullptr};
        cards[i] = {i, i, &mounts[i], nullptr};
        mounts[i].next = &cards[i];
    }

    for (int i = 0; i < Q; i++) {
        int C, P;
        cin >> C >> P;

        cards[C - 1].base->next = nullptr;
        cards[C - 1].base = &cards[P - 1];
        cards[P - 1].next = &cards[C - 1];
    }

    for (int i = 0; i < N; i++) {
        Card mount = mounts[i];
        Card card = mount;
        int count = 0;
        while(true) {
            if (card.next == nullptr) break;
            count++;
            card = *card.next;
        }

        cout << count;
        if (i == N - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}
