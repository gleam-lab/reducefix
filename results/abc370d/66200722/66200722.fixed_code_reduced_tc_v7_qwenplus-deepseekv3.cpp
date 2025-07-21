#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;
    vector<int> min_pos;
    vector<int> max_pos;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        min_pos.resize(n);
        max_pos.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            min_pos[i] = i;
            max_pos[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        min_pos[x] = min(min_pos[x], min_pos[y]);
        max_pos[x] = max(max_pos[x], max_pos[y]);
    }
};

void solve() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<map<int, int>> row(h);
    vector<map<int, int>> col(w);
    int total_walls = h * w;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!row[r].count(c)) {
            // Wall exists, destroy it
            row[r][c] = 1;
            col[c][r] = 1;
            total_walls--;
        } else {
            // No wall, find first walls in four directions
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                int pos = it_up->first;
                if (row[pos].count(c)) {
                    row[pos].erase(c);
                    col[c].erase(pos);
                    total_walls--;
                }
            }
            // Down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                int pos = it_down->first;
                if (row[pos].count(c)) {
                    row[pos].erase(c);
                    col[c].erase(pos);
                    total_walls--;
                }
            }
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                int pos = it_left->first;
                if (col[pos].count(r)) {
                    col[pos].erase(r);
                    row[r].erase(pos);
                    total_walls--;
                }
            }
            // Right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                int pos = it_right->first;
                if (col[pos].count(r)) {
                    col[pos].erase(r);
                    row[r].erase(pos);
                    total_walls--;
                }
            }
        }
    }

    cout << total_walls << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}