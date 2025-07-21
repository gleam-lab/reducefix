#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;

struct UF {
    int parent[MAXN * MAXN], rank[MAXN * MAXN];

    UF(int n, int m) {
        for (int i = 0; i < n * m; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] > rank[py]) swap(px, py);
        parent[px] = py;
        rank[py] += rank[px];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> A(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> grid(h, vector<int>(w, 0));
    UF uf(h * w, h * w);

    auto count_components = [&]() -> int {
        unordered_set<int> ids;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 1) {
                    ids.insert(uf.find(i * w + j));
                }
            }
        }
        return ids.size();
    };

    vector<int> results(y);
    for (int k = 0; k < y; ++k) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                grid[i][j] = A[i][j] > k ? 1 : 0;
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 0) continue;
                if (i > 0 && grid[i - 1][j] == 1) uf.unite(i * w + j, (i - 1) * w + j);
                if (i < h - 1 && grid[i + 1][j] == 1) uf.unite(i * w + j, (i + 1) * w + j);
                if (j > 0 && grid[i][j - 1] == 1) uf.unite(i * w + j, i * w + (j - 1));
                if (j < w - 1 && grid[i][j + 1] == 1) uf.unite(i * w + j, i * w + (j + 1));
            }
        }

        results[k] = count_components();
    }

    for (int i = 0; i < y; ++i) {
        cout << results[i] << '\n';
    }

    return 0;
}