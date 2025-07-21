#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int N = 200020, INF = 0x3f3f3f3f;
int n, m, q;

void solve() {
    cin >> n >> m >> q;
    vector<set<int>> row_walls(n + 1), col_walls(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    auto erase_wall = [&](int r, int c) {
        row_walls[r].erase(c);
        col_walls[c].erase(r);
    };

    while (q--) {
        int r, c;
        cin >> r >> c;
        if (row_walls[r].count(c)) {
            erase_wall(r, c);
            continue;
        }

        // Find the nearest walls in all four directions
        // Up
        auto it_up = col_walls[c].lower_bound(r);
        if (it_up != col_walls[c].begin()) {
            --it_up;
            erase_wall(*it_up, c);
        }
        // Down
        auto it_down = col_walls[c].lower_bound(r);
        if (it_down != col_walls[c].end()) {
            erase_wall(*it_down, c);
        }
        // Left
        auto it_left = row_walls[r].lower_bound(c);
        if (it_left != row_walls[r].begin()) {
            --it_left;
            erase_wall(r, *it_left);
        }
        // Right
        auto it_right = row_walls[r].lower_bound(c);
        if (it_right != row_walls[r].end()) {
            erase_wall(r, *it_right);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += row_walls[i].size();
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}