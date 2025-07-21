#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()
const int N = 200020, INF = 0x3f3f3f3f;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>> row_walls(n + 1);
    vector<set<int>> col_walls(m + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
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

        // Look right
        auto it = row_walls[r].lower_bound(c);
        if (it != row_walls[r].end()) {
            erase_wall(r, *it);
        }

        // Look left
        it = row_walls[r].lower_bound(c);
        if (it != row_walls[r].begin()) {
            --it;
            erase_wall(r, *it);
        }

        // Look down
        auto it2 = col_walls[c].lower_bound(r);
        if (it2 != col_walls[c].end()) {
            erase_wall(*it2, c);
        }

        // Look up
        it2 = col_walls[c].lower_bound(r);
        if (it2 != col_walls[c].begin()) {
            --it2;
            erase_wall(*it2, c);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
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