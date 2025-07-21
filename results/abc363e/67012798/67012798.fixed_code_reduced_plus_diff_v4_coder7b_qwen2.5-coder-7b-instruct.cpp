#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }
    
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (rank[u] > rank[v]) swap(u, v);
            parent[u] = v;
            if (rank[u] == rank[v]) ++rank[v];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<array<int, 4>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    UnionFind uf(H * W + 1); // Extra node for the sea

    auto isValid = [&](int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W;
    };

    auto addEdge = [&](int u, int v) {
        uf.unite(u, v);
    };

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int idx = i * W + j;
            for (auto &dir : directions) {
                int ni = i + dir[0], nj = j + dir[1];
                if (isValid(ni, nj)) {
                    int nidx = ni * W + nj;
                    if (A[ni][nj] <= A[i][j]) {
                        addEdge(idx, nidx);
                    }
                } else {
                    addEdge(idx, H * W); // Connect to sea
                }
            }
        }
    }

    vector<int> ans(Y + 1, H * W);
    for (int i = 1; i <= Y; i++) {
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                int idx = j * W + k;
                if (!visited[j][k] && A[j][k] > i) {
                    queue<int> q;
                    q.push(idx);
                    visited[j][k] = true;
                    while (!q.empty()) {
                        int u = q.front();
                        q.pop();
                        for (auto &dir : directions) {
                            int ni = u / W + dir[0], nj = u % W + dir[1];
                            if (isValid(ni, nj) && !visited[ni][nj] && A[ni][nj] > i) {
                                q.push(ni * W + nj);
                                visited[ni][nj] = true;
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                visited[j][k] = false;
            }
        }
        ans[i] -= uf.size(uf.find(H * W));
    }

    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}