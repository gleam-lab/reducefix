#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    
    // Initialize sets for rows and columns
    vector<set<pair<ll, ll>>> rows(h);
    vector<set<pair<ll, ll>>> cols(w);

    // Initially, all cells have walls
    rep(i, h) rep(j, w) {
        rows[i].insert({j, 1});
        cols[j].insert({i, 1});
    }

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--, c--;

        // Check if there is a wall at (r, c)
        auto it = rows[r].lower_bound({c, -1});
        if (it != rows[r].end() && it->first == c) {
            // Remove wall at (r, c)
            rows[r].erase(it);
            cols[c].erase({r, 1});
        } else {
            // Find walls to be destroyed
            pair<ll, ll> up = {INT_MAX, INT_MAX}, down = {-1, -1};
            pair<ll, ll> left = {INT_MAX, INT_MAX}, right = {-1, -1};

            if (it != rows[r].begin()) {
                --it;
                up = *it;
                ++it;
            }

            it = rows[r].upper_bound({c, -1});
            if (it != rows[r].end()) {
                down = *it;
            }

            it = cols[c].lower_bound({r, -1});
            if (it != cols[c].begin()) {
                --it;
                left = *it;
                ++it;
            }

            it = cols[c].upper_bound({r, -1});
            if (it != cols[c].end()) {
                right = *it;
            }

            // Destroy walls found
            if (up.second == 1) {
                rows[up.first].erase({c, 1});
                cols[c].erase({up.first, 1});
            }
            if (down.second == 1) {
                rows[down.first].erase({c, 1});
                cols[c].erase({down.first, 1});
            }
            if (left.second == 1) {
                cols[left.first].erase({r, 1});
                rows[r].erase({left.first, 1});
            }
            if (right.second == 1) {
                cols[right.first].erase({r, 1});
                rows[r].erase({right.first, 1});
            }
        }
    }

    // Count remaining walls
    ll ans = 0;
    rep(i, h) ans += rows[i].size();
    rep(j, w) ans += cols[j].size();

    // Each wall is counted twice, so divide by 2
    ans /= 2;

    cout << ans << endl;
    return 0;
}