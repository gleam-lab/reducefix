#include <bits/stdc++.h>
using namespace std;

#pragma optimize("3")
#pragma target("sse4")

const int dx[4] = {-1, 1, 0, 0}; // Up, Down, Left, Right
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    const int MAX = H * W;
    vector<bool> has_wall(H * W, true);
    array<vector<int>, 4> trees; // UP, DOWN, LEFT, RIGHT

    for (auto &t : trees) {
        t.resize(H * W);
    }

    auto idx = [&](int x, int y) { return x * W + y; };

    // Initialize Union-Find structures for each direction
    array<vector<int>, 4> parent;
    for (int d = 0; d < 4; ++d) {
        parent[d].resize(H * W);
        iota(parent[d].begin(), parent[d].end(), 0);
    }

    function<int(int, int, int)> find = [&](int d, int x, int y) {
        int id = idx(x, y);
        if (parent[d][id] != id) {
            parent[d][id] = parent[d][parent[d][id]];
            int nx = parent[d][id] / W;
            int ny = parent[d][id] % W;
            return find(d, nx, ny);
        }
        return id;
    };

    auto unite = [&](int d, int x, int y, int nx, int ny) {
        int id = idx(x, y);
        int nid = idx(nx, ny);
        parent[d][id] = nid;
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        int i = idx(r, c);

        if (has_wall[i]) {
            has_wall[i] = false;
            // Bomb placed on a wall cell: just remove the wall
            for (int d = 0; d < 4; ++d) {
                int x = r + dx[d];
                int y = c + dy[d];
                if (x >= 0 && x < H && y >= 0 && y < W) {
                    unite(d, r, c, x, y);
                }
            }
        } else {
            // Bomb placed on non-wall cell: destroy first walls in all directions
            for (int d = 0; d < 4; ++d) {
                int next_id = find(d, r, c);
                int nx = next_id / W;
                int ny = next_id % W;
                if (nx == r && ny == c) continue; // No wall found in this direction
                if (has_wall[next_id]) {
                    has_wall[next_id] = false;
                    int x = nx + dx[d];
                    int y = ny + dy[d];
                    if (x >= 0 && x < H && y >= 0 && y < W) {
                        unite(d, nx, ny, x, y);
                    }
                }
            }
        }
    }

    int count = 0;
    for (bool wall : has_wall) {
        if (wall) ++count;
    }

    cout << count << '\n';
    return 0;
}