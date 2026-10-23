#include "bits/stdc++.h"
#include <vector>

using namespace std;

class Node
{
public:
    vector<Node*> nodes;
    bool is_visited = false;
};

int main() {
    int N;
    cin >> N;

    vector<Node> nodes(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;

        nodes[A - 1].nodes.push_back(&nodes[B - 1]);
        nodes[B - 1].nodes.push_back(&nodes[A - 1]);
    }

    auto dfs = [&](auto dfs, Node* current, int length) -> int {
        if (current->is_visited)
            return length;

        return dfs(dfs, current->next, length + 1);
    };

    int result = dfs(dfs, &nodes[0], &nodes[1], 0);
}
