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
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            erase_wall(r, c);
            continue;
        }

        // Check up
        auto it_up = col_walls[c].lower_bound(r);
        if (it_up != col_walls[c].begin()) {
            --it_up;
            erase_wall(*it_up, c);
        }

        // Check down
        auto it_down = col_walls[c].lower_bound(r);
        if (it_down != col_walls[c].end()) {
            erase_wall(*it_down, c);
        }

        // Check left
        auto it_left = row_walls[r].lower_bound(c);
        if (it_left != row_walls[r].begin()) {
            --it_left;
            erase_wall(r, *it_left);
        }

        // Check right
        auto it_right = row_walls[r].lower_bound(c);
        if (it_right != row_walls[r].end()) {
            erase_wall(r, *it_right);
        }
    }

    ll remaining_walls = 0;
    for (int i = 1; i <= H; ++i) {
        remaining_walls += row_walls[i].size();
    }
    cout << remaining_walls << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}