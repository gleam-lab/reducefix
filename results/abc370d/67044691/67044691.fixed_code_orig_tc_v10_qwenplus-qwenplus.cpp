#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll H, W, Q;
    cin >> H >> W >> Q;

    vector<set<ll>> rows(H), cols(W);
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        if (rows[r].count(c)) {
            // There is a wall here, destroy it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Find the first walls in each direction
            vector<pair<ll, ll>> to_remove;

            // Up and Down (along column)
            auto& col_set = cols[c];
            auto it = col_set.lower_bound(r);
            if (it != col_set.end()) {
                // Down
                to_remove.emplace_back(*it, c);
            }
            if (it != col_set.begin()) {
                --it;
                // Up
                to_remove.emplace_back(*it, c);
            }

            // Left and Right (along row)
            auto& row_set = rows[r];
            it = row_set.lower_bound(c);
            if (it != row_set.end()) {
                // Right
                to_remove.emplace_back(r, *it);
            }
            if (it != row_set.begin()) {
                --it;
                // Left
                to_remove.emplace_back(r, *it);
            }

            // Remove the found walls
            for (auto [x, y] : to_remove) {
                rows[x].erase(y);
                cols[y].erase(x);
            }
        }
    }

    ll ans = 0;
    for (auto& row : rows) {
        ans += row.size();
    }
    cout << ans << '\n';

    return 0;
}