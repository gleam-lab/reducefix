#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h + 1), col(w + 1);
    for (ll i = 1; i <= h; ++i) {
        for (ll j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    set<pair<ll, ll>> walls;
    for (ll i = 1; i <= h; ++i) {
        for (ll j = 1; j <= w; ++j) {
            walls.insert({i, j});
        }
    }
    while (q--) {
        ll r, c;
        cin >> r >> c;
        if (walls.find({r, c}) != walls.end()) {
            walls.erase({r, c});
            row[r].erase(c);
            col[c].erase(r);
        } else {
            vector<pair<ll, ll>> to_remove;
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                to_remove.emplace_back(r, *it_left);
            }
            // Right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                to_remove.emplace_back(r, *it_right);
            }
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                to_remove.emplace_back(*it_up, c);
            }
            // Down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                to_remove.emplace_back(*it_down, c);
            }
            for (auto &p : to_remove) {
                ll x = p.first, y = p.second;
                if (walls.find({x, y}) != walls.end()) {
                    walls.erase({x, y});
                    row[x].erase(y);
                    col[y].erase(x);
                }
            }
        }
    }
    cout << walls.size() << '\n';
    return 0;
}