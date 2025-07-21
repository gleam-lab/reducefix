#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

const int MAXN = 400005;

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
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            rank[pu] += rank[pv];
        } else {
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    UnionFind uf(H * W + 2);
    unordered_map<int, set<int>> rows, cols;
    vector<int> walls(H * W + 2, 1);

    while(Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        int id = r * W + c;
        if(walls[id] == 0) {
            // If there is already no wall, just skip
            continue;
        }

        // Remove the current wall
        walls[id] = 0;
        rows[r].erase(id);
        cols[c].erase(id);

        // Check and remove walls above
        if(r > 0 && rows[r-1].size()) {
            int up_id = (r-1) * W + c;
            if(walls[up_id] == 0) continue;
            uf.unite(up_id, id);
        }

        // Check and remove walls below
        if(r < H-1 && rows[r+1].size()) {
            int down_id = (r+1) * W + c;
            if(walls[down_id] == 0) continue;
            uf.unite(down_id, id);
        }

        // Check and remove walls to the left
        if(c > 0 && cols[c-1].size()) {
            int left_id = r * W + (c-1);
            if(walls[left_id] == 0) continue;
            uf.unite(left_id, id);
        }

        // Check and remove walls to the right
        if(c < W-1 && cols[c+1].size()) {
            int right_id = r * W + (c+1);
            if(walls[right_id] == 0) continue;
            uf.unite(right_id, id);
        }
    }

    int total_walls = 0;
    for(int i = 0; i < H * W; ++i) {
        if(walls[i] == 0) continue;
        int root = uf.find(i);
        if(root == i) total_walls++;
    }

    cout << total_walls << endl;

    return 0;
}