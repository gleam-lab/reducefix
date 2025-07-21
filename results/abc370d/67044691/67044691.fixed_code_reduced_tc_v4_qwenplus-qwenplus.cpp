#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, r) for(ll i = 0; i < (ll)r; ++i)
#define vl vector<ll>
#define vb vector<bool>
#define vi vector<int>
#define vc vector<char>
#define vvb vector<vb>
#define vvl vector<vl>
#define vvi vector<vi>
#define vs vector<string>
#define vvc vector<vc>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((ll)a.size())
#define get_pos(set, val) set.lower_bound(val)

// Data structure to maintain the positions of walls in each row and column
vector<set<ll>> row_walls;
vector<set<ll>> col_walls;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, w, q;
    cin >> h >> w >> q;
    
    // Initialize each row and column with all wall positions
    row_walls.resize(h);
    col_walls.resize(w);
    
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        auto it = row_walls[r].find(c);
        if (it != row_walls[r].end()) {
            // Wall exists at this position - remove it
            row_walls[r].erase(it);
            col_walls[c].erase(r);
        } else {
            // No wall here - destroy nearest walls in each direction
            vl pos(4, -1); // up, down, left, right

            // Left
            auto leftIt = row_walls[r].lower_bound(c);
            if (leftIt != row_walls[r].begin()) {
                --leftIt;
                pos[2] = *leftIt;
            }

            // Right
            auto rightIt = row_walls[r].upper_bound(c);
            if (rightIt != row_walls[r].end()) {
                pos[3] = *rightIt;
            }

            // Up
            auto upIt = col_walls[c].lower_bound(r);
            if (upIt != col_walls[c].begin()) {
                --upIt;
                pos[0] = *upIt;
            }

            // Down
            auto downIt = col_walls[c].upper_bound(r);
            if (downIt != col_walls[c].end()) {
                pos[1] = *downIt;
            }

            // Remove found walls
            if (pos[0] != -1) {
                row_walls[pos[0]].erase(c);
                col_walls[c].erase(pos[0]);
            }
            if (pos[1] != -1) {
                row_walls[pos[1]].erase(c);
                col_walls[c].erase(pos[1]);
            }
            if (pos[2] != -1) {
                row_walls[r].erase(pos[2]);
                col_walls[pos[2]].erase(r);
            }
            if (pos[3] != -1) {
                row_walls[r].erase(pos[3]);
                col_walls[pos[3]].erase(r);
            }
        }
    }

    // Count remaining walls
    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        ans += row_walls[i].size();
    }
    cout << ans << endl;

    return 0;
}