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