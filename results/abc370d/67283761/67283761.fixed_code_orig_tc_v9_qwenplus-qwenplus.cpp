#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    int rows, cols;

    DSU(int r, int c) : rows(r), cols(c) {
        parent.resize(rows * cols);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    const int N = H * W;
    vector<bool> alive(N, true);

    // DSU structures for directions: 0=up, 1=down, 2=left, 3=right
    array<vector<int>, 4> dir_parent;

    dir_parent[0] = vector<int>(N); // Up
    dir_parent[1] = vector<int>(N); // Down
    dir_parent[2] = vector<int>(N); // Left
    dir_parent[3] = vector<int>(N); // Right

    auto index = [&](int r, int c) { return (r - 1) * W + (c - 1); };

    // Initialize DSUs
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int idx = i * W + j;
            dir_parent[0][idx] = idx; // Up
            dir_parent[1][idx] = idx; // Down
            dir_parent[2][idx] = idx; // Left
            dir_parent[3][idx] = idx; // Right
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int idx = i * W + j;
            if (i > 0) dir_parent[0][idx] = idx; // Initially point to self
            if (i < H - 1) dir_parent[1][idx] = idx;
            if (j > 0) dir_parent[2][idx] = idx;
            if (j < W - 1) dir_parent[3][idx] = idx;
        }
    }

    auto explode = [&](int r, int c) {
        int idx = index(r, c);
        if (alive[idx]) {
            alive[idx] = false;
            return;
        }

        array<pair<int, int>, 4> dirs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int d = 0; d < 4; ++d) {
            int x = r - 1, y = c - 1;
            int cur = x * W + y;
            int nx = x, ny = y;
            while (true) {
                nx += dirs[d].first;
                ny += dirs[d].second;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) break;
                int next_idx = nx * W + ny;
                int rep = dir_parent[d][next_idx];
                if (alive[rep]) {
                    alive[rep] = false;
                    // Move pointer past the destroyed wall
                    dir_parent[d][next_idx] = dir_parent[d][rep];
                    break;
                }
            }
        }
    };

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        explode(R, C);
    }

    cout << count(alive.begin(), alive.end(), true) << endl;
}