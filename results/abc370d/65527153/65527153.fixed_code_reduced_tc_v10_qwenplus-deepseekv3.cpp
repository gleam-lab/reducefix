#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(), x.end()
const int N = 200020, INF = 0x3f3f3f3f;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row_walls(H + 1), col_walls(W + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    auto erase_wall = [&](int r, int c) {
        row_walls[r].erase(c);
        col_walls[c].erase(r);
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (row_walls[R].count(C)) {
            erase_wall(R, C);
            continue;
        }

        // Up direction
        auto it_up = col_walls[C].lower_bound(R);
        if (it_up != col_walls[C].begin()) {
            --it_up;
            erase_wall(*it_up, C);
        }

        // Down direction
        auto it_down = col_walls[C].lower_bound(R);
        if (it_down != col_walls[C].end()) {
            erase_wall(*it_down, C);
        }

        // Left direction
        auto it_left = row_walls[R].lower_bound(C);
        if (it_left != row_walls[R].begin()) {
            --it_left;
            erase_wall(R, *it_left);
        }

        // Right direction
        auto it_right = row_walls[R].lower_bound(C);
        if (it_right != row_walls[R].end()) {
            erase_wall(R, *it_right);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= H; ++i) {
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