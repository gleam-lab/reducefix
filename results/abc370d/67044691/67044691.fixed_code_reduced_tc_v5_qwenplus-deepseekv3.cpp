#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, r) for (ll i = 0; i < (ll)r; i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

int main() {
    ll h, w, q; cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    rep(i, h) rep(j, w) {
        row[i].insert(j);
        col[j].insert(i);
    }
    ll ans = h * w;
    rep(iii, q) {
        ll r, c; cin >> r >> c;
        r--; c--;
        if (row[r].find(c) != row[r].end()) {
            row[r].erase(c);
            col[c].erase(r);
            ans--;
        } else {
            // Check up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                ll i = *it_up;
                if (row[i].find(c) != row[i].end()) {
                    row[i].erase(c);
                    col[c].erase(i);
                    ans--;
                }
            }
            // Check down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                ll i = *it_down;
                if (row[i].find(c) != row[i].end()) {
                    row[i].erase(c);
                    col[c].erase(i);
                    ans--;
                }
            }
            // Check left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                ll j = *it_left;
                if (col[j].find(r) != col[j].end()) {
                    col[j].erase(r);
                    row[r].erase(j);
                    ans--;
                }
            }
            // Check right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                ll j = *it_right;
                if (col[j].find(r) != col[j].end()) {
                    col[j].erase(r);
                    row[r].erase(j);
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
}