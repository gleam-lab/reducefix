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
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv]) swap(pu, pv);
            parent[pv] = pu;
            if (rank[pu] == rank[pv]) rank[pu]++;
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int id = i * W + j;
            if (i > 0) edges.emplace_back(A[i - 1][j] - A[i][j], make_pair(id, id - W));
            if (j > 0) edges.emplace_back(A[i][j - 1] - A[i][j], make_pair(id, id - 1));
        }
    }
    
    sort(edges.rbegin(), edges.rend());
    
    UnionFind uf(H * W);
    vector<bool> sinked(H * W, false);
    int count = H * W;
    
    for (const auto& [diff, ids] : edges) {
        int u = ids.first, v = ids.second;
        int pu = uf.find(u), pv = uf.find(v);
        if (pu != pv && diff <= 0) {
            uf.unite(u, v);
            sinked[u] = true;
            sinked[v] = true;
            count--;
        }
    }
    
    vector<int> areas(Y + 1, count);
    
    for (int i = 1; i <= Y; ++i) {
        while (!edges.empty() && edges.back().first <= i) {
            const auto& [diff, ids] = edges.back();
            int u = ids.first, v = ids.second;
            int pu = uf.find(u), pv = uf.find(v);
            if (pu != pv && diff <= i) {
                uf.unite(u, v);
                sinked[u] = true;
                sinked[v] = true;
                count--;
            }
            edges.pop_back();
        }
        areas[i] = count;
    }
    
    for (int i = 1; i <= Y; ++i) {
        cout << areas[Y - i] << '\n';
    }
    
    return 0;
}