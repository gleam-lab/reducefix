#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return;
        if (rank[rootX] > rank[rootY]) swap(rootX, rootY);
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) ++rank[rootY];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j]; --A[i][j];
        }
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i > 0) edges.emplace_back(A[i][j], make_pair(i, j), make_pair(i - 1, j));
            if (j > 0) edges.emplace_back(A[i][j], make_pair(i, j), make_pair(i, j - 1));
        }
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(H * W);
    int ans = H * W;
    for (const auto& [height, p1, p2] : edges) {
        if (uf.find(p1.first * W + p1.second) == uf.find(p2.first * W + p2.second)) continue;
        uf.unite(p1.first * W + p1.second, p2.first * W + p2.second);
        --ans;
    }

    for (int i = 0; i < Y; ++i) {
        cout << ans << '\n';
    }

    return 0;
}