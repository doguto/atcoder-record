#include "bits/stdc++.h"

using namespace std;
#include <vector>

// 無向グラフの閉路判定
class UnionFind
{
public:
    // 頂点情報のみ受け取る
    UnionFind(int n) {
        parents = std::vector<int>(n, -1);
        sizes = std::vector<int>(n, 1);
    }

    int root(int i) {
        if (parents[i] < 0) return i;
        return parents[i] = root(parents[i]);
    }

    // i が所属する部分木の大きさ
    int rootSize(int i) {
        // This is Ilegal
        return sizes[root(i)];
    }

    int size(int i) {
        return sizes[i];
    }

    // true: 閉路が出来ない, false: 閉路が出来る
    bool connect(int i, int j) {
        int a = root(i);
        int b = root(j);
        if (a == b) return false;

        // a が大きいことを保証する
        if (size(a) < size(b)) {
            std::swap(a, b);
        }

        // Size の更新. root に接続することが保証されている
        sizes[a] += sizes[b];
        parents[b] = a;
        return true;
    }

    bool isConnect(int i, int j) {
        return root(i) == root(j);
    }

private:
    // 自分が根の時: 負の数で絶対値は木の大きさを示す
    // 正の時: 自分(i)の親を示す
    std::vector<int> parents;
    std::vector<int> sizes;
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);
    vector<pair<int, int>> bridges;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        bridges.push_back({a - 1, b - 1});
    }

    stack<long long> score_stack;
    long long ns = ((long long)N * (N - 1)) / 2;

    for (int i = M - 1; i >= 0; i--) {
        score_stack.push(ns);
        if (!uf.isConnect(bridges[i].first, bridges[i].second)) {
            // cout << "Hoge" << endl;
            ns -= uf.rootSize(bridges[i].first) * uf.rootSize(bridges[i].second);
        }
        uf.connect(bridges[i].first, bridges[i].second);
    }

    int size = score_stack.size();

    for (int i = 0; i < size; i++) {
        long long tmp = score_stack.top();
        score_stack.pop();
        cout << tmp << endl;
    }

    // for (int i = 0; i < M; i++) {
    //     int a, b; // 1~N
    //     cin >> a >> b;
    //     uf.connect(a - 1, b - 1);
    //     bridges.push_back({a - 1, b - 1});
    // }

    // int score = 0;

    // for (int i = 0; i < M; i++) {
    //     int size = uf.rootSize(bridges[i].first);
    //     cout << "Size: " << size << endl;
    //     uf.disconnect(bridges[i].first, bridges[i].second);

    //     if (!uf.isConnetct(bridges[i].first, bridges[i].second)) {
    //         score += uf.rootSize(bridges[i].first) * uf.rootSize(bridges[i].second);
    //     }
    //     cout << score << endl;
    // }
}
