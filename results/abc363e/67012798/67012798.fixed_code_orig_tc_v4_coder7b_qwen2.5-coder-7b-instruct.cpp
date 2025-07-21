#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

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
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
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

    UnionFind uf(H * W);
    vector<int> componentCount(H * W, 1);
    vector<int> area(H * W, 1);

    function<void(int)> updateArea = [&](int idx) {
        int r = idx / W, c = idx % W;
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d], nc = c + dy[d];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && A[r][c] <= A[nr][nc]) {
                int neighborIdx = nr * W + nc;
                if (uf.find(idx) != uf.find(neighborIdx)) {
                    uf.unite(idx, neighborIdx);
                    componentCount[uf.find(idx)] += componentCount[neighborIdx];
                    area[uf.find(idx)] += area[neighborIdx];
                    componentCount[neighborIdx] = 0;
                    area[neighborIdx] = 0;
                }
            }
        }
    };

    vector<int> result(Y + 1);
    for (int i = 1; i <= Y; i++) {
        for (int r = 0; r < H; r++) {
            for (int c = 0; c < W; c++) {
                if (A[r][c] <= i) {
                    int idx = r * W + c;
                    if (componentCount[idx] == 1) {
                        result[i] += area[idx];
                    }
                    updateArea(idx);
                }
            }
        }
        result[i] -= result[i - 1];
    }

    for (int i = 1; i <= Y; i++) {
        cout << result[i] << endl;
    }

    return 0;
}