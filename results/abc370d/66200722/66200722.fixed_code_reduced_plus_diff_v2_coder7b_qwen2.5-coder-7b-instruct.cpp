#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 400005;
int parent[MAXN], rank[MAXN];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<unordered_map<int, int>> s(h), t(w);
    for (int i = 0; i < h; ++i) parent[i * w] = i * w, rank[i * w] = 0;
    for (int j = 0; j < w; ++j) parent[j] = j, rank[j] = 0;

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (s[r].find(c) == s[r].end()) {
            s[r][c] = t[c][r] = parent[r * w + c];
            continue;
        }

        int root = s[r][c];
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) continue;
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < h && nc >= 0 && nc < w && s[nr].find(nc) != s[nr].end()) {
                    int other_root = s[nr][nc];
                    if (other_root != root) {
                        unite(root, other_root);
                        root = find(root);
                    }
                }
            }
        }

        s[r].erase(c);
        t[c].erase(r);
    }

    int ans = h * w;
    for (int i = 0; i < h; ++i) ans -= s[i].size();
    for (int j = 0; j < w; ++j) ans -= t[j].size();

    cout << ans << endl;

    return 0;
}