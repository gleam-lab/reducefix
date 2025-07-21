#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,r) for(ll i=0;i<(ll)r;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define vvb vector<vector<bool>>
#define vvl vector<vector<ll>>
#define vvc vector<vector<char>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    
    // For each row, we keep track of columns that have walls
    vector<set<ll>> rows(h);
    // For each column, we keep track of rows that have walls
    vector<set<ll>> cols(w);
    
    // Initially, every cell has a wall
    for (ll r = 0; r < h; ++r) {
        for (ll c = 0; c < w; ++c) {
            rows[r].insert(c);
            cols[c].insert(r);
        }
    }

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        auto hit = rows[r].find(c);
        if (hit != rows[r].end()) {
            // Wall exists at the location: destroy it
            rows[r].erase(hit);
            cols[c].erase(cols[c].find(r));
        } else {
            // Bomb explodes in four directions
            // Right direction
            auto right = rows[r].upper_bound(c);
            if (right != rows[r].end()) {
                ll col = *right;
                rows[r].erase(col);
                cols[col].erase(r);
            }

            // Left direction
            auto left = rows[r].lower_bound(c);
            if (left != rows[r].begin()) {
                --left;
                ll col = *left;
                rows[r].erase(col);
                cols[col].erase(r);
            }

            // Down direction
            auto down = cols[c].upper_bound(r);
            if (down != cols[c].end()) {
                ll row = *down;
                cols[c].erase(down);
                rows[row].erase(c);
            }

            // Up direction
            auto up = cols[c].lower_bound(r);
            if (up != cols[c].begin()) {
                --up;
                ll row = *up;
                cols[c].erase(up);
                rows[row].erase(c);
            }
        }
    }

    ll remaining = 0;
    for (ll i = 0; i < h; ++i) {
        remaining += rows[i].size();
    }
    cout << remaining << endl;

    return 0;
}