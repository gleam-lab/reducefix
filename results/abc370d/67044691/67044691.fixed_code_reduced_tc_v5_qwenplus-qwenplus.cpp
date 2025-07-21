#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, r) for (ll i = 0; i < (ll)r; ++i)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvvi vector<vector<vector<int>>>
#define vvvl vector<vector<vector<ll>>>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) ((int)(x).size())
#define pb push_back
#define fi first
#define se second

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll h, w, q;
    cin >> h >> w >> q;

    // For each row and column, keep a set of remaining walls (by column/row index)
    vector<set<ll>> rows(h), cols(w);

    // Initialize all walls present
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there's a wall at the bomb position
        if (rows[r].count(c)) {
            // Destroy wall at (r,c)
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Look in four directions
            array<tuple<ll, ll>, 4> to_remove;

            // Right in row
            auto it = rows[r].upper_bound(c);
            if (it != rows[r].end()) to_remove[0] = {r, *it};

            // Left in row
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                to_remove[1] = {r, *it};
            }

            // Down in column
            auto cit = cols[c].upper_bound(r);
            if (cit != cols[c].end()) to_remove[2] = {*cit, c};

            // Up in column
            cit = cols[c].lower_bound(r);
            if (cit != cols[c].begin()) {
                --cit;
                to_remove[3] = {*cit, c};
            }

            // Remove the found walls
            for (const auto& [rr, cc] : to_remove) {
                if (rr != -1 && rows[rr].count(cc)) {
                    rows[rr].erase(cc);
                    cols[cc].erase(rr);
                }
            }
        }
    }

    // Count remaining walls
    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << "\n";

    return 0;
}