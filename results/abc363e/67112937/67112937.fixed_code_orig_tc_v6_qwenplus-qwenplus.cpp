#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_A = 100005;
int H, W, Y;
vector<vector<int>> A;

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    // Create a grid with unique IDs
    int N = H * W;
    DSU dsu(N + 2); // N+1: sea node
    vector<vector<int>> val_pos(MAX_A + 2);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int id = i * W + j;
            val_pos[A[i][j]].push_back(id);
        }
    }

    // Prepare answer array
    vector<int> ans(Y + 2, H * W);
    const int SEA_NODE = H * W + 1;

    // Process from lowest to highest elevation
    for (int h = 1; h <= MAX_A; ++h) {
        for (int id : val_pos[h]) {
            int r = id / W, c = id % W;
            // Connect with adjacent cells if they are <= current height or already processed
            auto connect = [&](int nr, int nc) {
                if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                    int nid = nr * W + nc;
                    if (A[nr][nc] <= h) {
                        dsu.unite(id, nid);
                    }
                }
            };
            connect(r - 1, c);
            connect(r + 1, c);
            connect(r, c - 1);
            connect(r, c + 1);
            // Connect with sea if on border
            if (r == 0 || r == H - 1 || c == 0 || c == W - 1) {
                dsu.unite(id, SEA_NODE);
            }
        }

        // Count land area still above water
        int sea_root = dsu.find(SEA_NODE);
        for (int id : val_pos[h]) {
            int root = dsu.find(id);
            if (root != sea_root) {
                // This land is disconnected from sea
                dsu.unite(id, SEA_NODE); // Mark it as sunk in next steps
            } else {
                ans[h]--;
            }
        }
    }

    // Handle queries
    for (int y = 1; y <= Y; ++y) {
        cout << ans[y] << '\n';
    }

    return 0;
}