#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 400005;

int parent[MAXN];

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (parent[x] > parent[y]) swap(x, y);
    parent[x] += parent[y];
    parent[y] = x;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true));

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!grid[r][c]) {
            for (int i = 0; i < w; ++i) {
                if (grid[r][i]) {
                    unite(r * w + i, r * w + c);
                    break;
                }
            }
            for (int i = 0; i < h; ++i) {
                if (grid[i][c]) {
                    unite(i * w + c, r * w + c);
                    break;
                }
            }
        }

        grid[r][c] = false;
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] && !find(i * w + j)) {
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}