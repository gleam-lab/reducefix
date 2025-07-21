#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row_walls(H), col_walls(W);
    rep(i, H) rep(j, W) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    ll ans = (ll)H * W;
    ll cnt = 0;
    auto erase_wall = [&](int r, int c) {
        if (row_walls[r].count(c)) {
            cnt++;
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        }
    };
    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        if (row_walls[R].count(C)) {
            erase_wall(R, C);
            continue;
        }
        // Up
        auto it_up = col_walls[C].lower_bound(R);
        if (it_up != col_walls[C].begin()) {
            --it_up;
            erase_wall(*it_up, C);
        }
        // Down
        auto it_down = col_walls[C].lower_bound(R);
        if (it_down != col_walls[C].end()) {
            erase_wall(*it_down, C);
        }
        // Left
        auto it_left = row_walls[R].lower_bound(C);
        if (it_left != row_walls[R].begin()) {
            --it_left;
            erase_wall(R, *it_left);
        }
        // Right
        auto it_right = row_walls[R].lower_bound(C);
        if (it_right != row_walls[R].end()) {
            erase_wall(R, *it_right);
        }
    }
    cout << ans - cnt << endl;
    return 0;
}