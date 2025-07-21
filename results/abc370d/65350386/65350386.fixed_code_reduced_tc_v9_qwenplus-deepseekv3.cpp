#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);
    
    rep(i, h) rep(j, w) {
        rows[i].insert(j);
        cols[j].insert(i);
    }
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                int up = *prev(it_up);
                rows[up].erase(c);
                cols[c].erase(up);
            }
            
            auto it_down = cols[c].lower_bound(r);
            if (it_down != cols[c].end()) {
                int down = *it_down;
                rows[down].erase(c);
                cols[c].erase(down);
            }
            
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                int left = *prev(it_left);
                rows[r].erase(left);
                cols[left].erase(r);
            }
            
            auto it_right = rows[r].lower_bound(c);
            if (it_right != rows[r].end()) {
                int right = *it_right;
                rows[r].erase(right);
                cols[right].erase(r);
            }
        }
    }
    
    int ans = 0;
    rep(i, h) ans += rows[i].size();
    cout << ans << "\n";
    
    return 0;
}