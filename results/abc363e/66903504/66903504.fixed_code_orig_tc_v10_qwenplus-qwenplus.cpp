#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = int64_t;
using pii = pair<int, int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Coordinate compression of elevations
    set<int> elevation_set;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            elevation_set.insert(A[i][j]);
        }
    }
    map<int, int> elevation_to_idx;
    int idx = 0;
    for (int val : elevation_set) {
        elevation_to_idx[val] = idx++;
    }
    vector<vector<int>> compressed(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            compressed[i][j] = elevation_to_idx[A[i][j]];
        }
    }

    // Prepare events by elevation level
    vector<vector<pii>> level_events(idx);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            level_events[compressed[i][j]].emplace_back(i, j);
        }
    }

    // Union-Find with sea and island tracking
    struct DSU {
        vector<int> parent, size;
        DSU(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        bool unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return false;
            if (size[px] < size[py]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
            return true;
        }
        int get_size(int x) {
            return size[find(x)];
        }
    };

    int total_cells = H * W;
    vector<bool> is_submerged(H * W, false);
    DSU dsu(H * W);
    vector<int> submerged_count(idx + 2, 0); // submerged_count[y] stores how many cells are submerged by year y

    auto coord = [&](int i, int j) {
        return i * W + j;
    };

    vector<int> current_level(idx + 2, 0);
    for (int y = 0; y < idx; ++y) {
        for (auto [i, j] : level_events[y]) {
            int u = coord(i, j);
            is_submerged[u] = true;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    int v = coord(ni, nj);
                    if (is_submerged[v]) {
                        dsu.unite(u, v);
                    }
                }
            }
        }
        // Count total submerged nodes in the union with any boundary cell
        set<int> roots;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                    int c = coord(i, j);
                    if (is_submerged[c]) {
                        roots.insert(dsu.find(c));
                    }
                }
            }
        }
        int submerged = 0;
        for (int root : roots) {
            submerged += dsu.get_size(root);
        }
        submerged_count[elevation_set.begin()[y]] = submerged;
    }

    // Answer queries using binary search on elevation values
    vector<int> elevations(elevation_set.begin(), elevation_set.end());
    for (int q = 0; q <= Y; ++q) {
        int low = 0, high = idx - 1;
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (elevations[mid] <= q) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << total_cells - submerged_count[q] << "\n";
    }

    return 0;
}