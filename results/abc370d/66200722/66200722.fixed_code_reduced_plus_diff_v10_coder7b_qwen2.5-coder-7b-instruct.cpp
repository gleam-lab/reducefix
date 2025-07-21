#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAXN = 400005;
const int MAXQ = 200005;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if(parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        rank[pu] += rank[pv];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    UnionFind uf(h * w + 2); // Extra nodes for boundaries
    vector<pair<int, int>> walls(h * w);
    unordered_map<int, int> rowWalls[h];
    unordered_map<int, int> colWalls[w];

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            walls[i * w + j] = {i, j};
            rowWalls[i][j] = i * w + j;
            colWalls[j][i] = i * w + j;
        }
    }

    vector<bool> destroyed(h * w, false);
    for(int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if(destroyed[rowWalls[r][c]]) {
            for(int i = 0; i < w; ++i) {
                if(colWalls[i][r] != rowWalls[r][c] && !destroyed[colWalls[i][r]]) {
                    uf.unite(rowWalls[r][c], colWalls[i][r]);
                    destroyed[colWalls[i][r]] = true;
                }
            }
            for(int j = 0; j < h; ++j) {
                if(rowWalls[j][c] != rowWalls[r][c] && !destroyed[rowWalls[j][c]]) {
                    uf.unite(rowWalls[r][c], rowWalls[j][c]);
                    destroyed[rowWalls[j][c]] = true;
                }
            }
        } else {
            destroyed[rowWalls[r][c]] = true;
        }
    }

    int remainingWalls = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(!destroyed[rowWalls[i][j]]) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}