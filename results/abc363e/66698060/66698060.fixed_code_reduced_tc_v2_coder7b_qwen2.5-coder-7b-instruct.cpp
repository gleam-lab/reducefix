#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct UnionFind {
    int par[MAXN * MAXN];

    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void unite(int x, int y) {
        par[find(x)] = find(y);
    }
};

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    UnionFind uf(h * w + 1);
    vector<int> rank(h * w + 1, 0);
    vector<bool> seen(h * w, false);

    auto index = [&](int i, int j) { return i * w + j; };

    function<void(int)> dfs = [&](int i, int j) {
        if (i < 0 || i >= h || j < 0 || j >= w || seen[index(i, j)]) return;
        seen[index(i, j)] = true;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || grid[ni][nj] <= grid[i][j]) continue;
            dfs(ni, nj);
        }
    };

    for (int i = 0; i < h; ++i) {
        dfs(i, 0);
        dfs(i, w - 1);
    }
    for (int j = 1; j < w - 1; ++j) {
        dfs(0, j);
        dfs(h - 1, j);
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!seen[index(i, j)]) {
                uf.unite(index(i, j), h * w); // Connect to dummy node
            } else {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= h || nj < 0 || nj >= w || grid[ni][nj] > grid[i][j]) continue;
                    uf.unite(index(i, j), index(ni, nj));
                }
            }
        }
    }

    for (int t = 1; t <= y; ++t) {
        int components = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] > t) {
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni < 0 || ni >= h || nj < 0 || nj >= w || grid[ni][nj] <= t) continue;
                        uf.unite(index(i, j), index(ni, nj));
                    }
                }
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] > t && uf.find(index(i, j)) == index(i, j)) {
                    components++;
                }
            }
        }
        cout << components << endl;
    }

    return 0;
}