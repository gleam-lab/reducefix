#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll h, w, q;
    cin >> h >> w >> q;
    
    vector<set<ll>> row(h), col(w);
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Find first walls in four directions
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                row[*it_up].erase(c);
                col[c].erase(it_up);
            }
            // Down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                row[*it_down].erase(c);
                col[c].erase(it_down);
            }
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                col[*it_left].erase(r);
                row[r].erase(it_left);
            }
            // Right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                col[*it_right].erase(r);
                row[r].erase(it_right);
            }
        }
    }
    
    ll ans = 0;
    for (auto& r : row) {
        ans += r.size();
    }
    cout << ans << '\n';
    
    return 0;
}