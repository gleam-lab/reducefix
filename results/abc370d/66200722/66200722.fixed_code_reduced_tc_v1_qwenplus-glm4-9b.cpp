#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_H = 400005;
const int MAX_W = 400005;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) {
        parent.resize(size + 1);
        rank.resize(size + 1, 0);
        for (int i = 0; i <= size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int h, w, q;
UnionFind uf(MAX_H + MAX_W);
vector<bool> wall(MAX_H * MAX_W + 1, true);
map<pair<int, int>, pair<int, int>> rowCol;

void solve() {
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        int index = r * w + c;
        if (wall[index]) {
            wall[index] = false;
        } else {
            // Find the connected components in the row and column
            int rootRow = uf.find(r);
            int rootCol = uf.find(c);
            for (int i = 0; i <= h; ++i) {
                if (uf.find(i) == rootRow && wall[i * w + c]) {
                    wall[i * w + c] = false;
                }
            }
            for (int j = 0; j <= w; ++j) {
                if (uf.find(j) == rootCol && wall[r * w + j]) {
                    wall[r * w + j] = false;
                }
            }
            uf.unite(rootRow, rootCol);
        }
    }

    int remainingWalls = 0;
    for (int i = 0; i < MAX_H * MAX_W; ++i) {
        if (wall[i]) {
            remainingWalls++;
        }
    }
    cout << remainingWalls << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> h >> w >> q;
    solve();
    return 0;
}