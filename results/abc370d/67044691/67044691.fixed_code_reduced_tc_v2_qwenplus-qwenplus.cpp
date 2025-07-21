#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,r) for(ll i=0;i<(ll)r;i++)
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
    vector<set<ll>> row(h), col(w);
    
    // Initialize each cell as a wall exists
    rep(i, h) {
        rep(j, w) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    rep(qq, q) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        // If there is a wall at (r, c), remove it and continue
        if (row[r].find(c) != row[r].end()) {
            row[r].erase(c);
            col[c].erase(r);
            continue;
        }

        // Directions: right, left, down, up
        // We'll store the walls to be destroyed in this array
        vector<pair<ll, ll>> destroy;

        // Right
        auto right = row[r].upper_bound(c);
        if (right != row[r].end()) {
            destroy.push_back({r, *right});
        }

        // Left
        auto left = row[r].lower_bound(c);
        if (left != row[r].begin()) {
            --left;
            destroy.push_back({r, *left});
        }

        // Down
        auto down = col[c].upper_bound(r);
        if (down != col[c].end()) {
            destroy.push_back({*down, c});
        }

        // Up
        auto up = col[c].lower_bound(r);
        if (up != col[c].begin()) {
            --up;
            destroy.push_back({*up, c});
        }

        // Remove all found walls
        for (auto [x, y] : destroy) {
            row[x].erase(y);
            col[y].erase(x);
        }
    }

    // Count remaining walls
    ll ans = 0;
    rep(i, h) {
        ans += row[i].size();
    }
    cout << ans << endl;
}