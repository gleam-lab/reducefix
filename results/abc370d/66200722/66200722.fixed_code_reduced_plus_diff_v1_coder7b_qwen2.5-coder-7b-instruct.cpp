#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> par, rank;

    UnionFind(int n): par(n), rank(n, 0) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        par[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w, 1));

    UnionFind uf(h * w + 2);
    int boundary_id = h * w;
    int empty_id = h * w + 1;

    function<void(int, int)> destroy_walls = [&](int r, int c) {
        int id = r * w + c;
        if (grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0;
        if (r > 0 && grid[r - 1][c] == 1) {
            uf.unite(id, (r - 1) * w + c);
        }
        if (r < h - 1 && grid[r + 1][c] == 1) {
            uf.unite(id, (r + 1) * w + c);
        }
        if (c > 0 && grid[r][c - 1] == 1) {
            uf.unite(id, r * w + (c - 1));
        }
        if (c < w - 1 && grid[r][c + 1] == 1) {
            uf.unite(id, r * w + (c + 1));
        }
    };

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c] == 0) {
            int id = r * w + c;
            int root = uf.find(id);
            if (root != boundary_id) {
                int new_root = uf.find(root);
                if (new_root != boundary_id) {
                    if (uf.rank[new_root] == uf.rank[root] + 1) {
                        uf.rank[new_root]--;
                    }
                    uf.par[root] = new_root;
                }
            }
        } else {
            destroy_walls(r, c);
            destroy_walls(r + 1, c);
            destroy_walls(r - 1, c);
            destroy_walls(r, c + 1);
            destroy_walls(r, c - 1);
        }
    }

    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}