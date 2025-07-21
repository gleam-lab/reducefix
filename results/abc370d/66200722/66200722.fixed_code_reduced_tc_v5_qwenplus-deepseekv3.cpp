#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> rows(h + 1), cols(w + 1);
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    long long total = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
            total--;
        } else {
            // Check up
            auto it = cols[c].upper_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int i = *it;
                if (rows[i].count(c)) {
                    rows[i].erase(c);
                    cols[c].erase(i);
                    total--;
                }
            }
            
            // Check down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int i = *it;
                if (rows[i].count(c)) {
                    rows[i].erase(c);
                    cols[c].erase(i);
                    total--;
                }
            }
            
            // Check left
            it = rows[r].upper_bound(c);
            if (it != rows[r].begin()) {
                --it;
                int j = *it;
                if (cols[j].count(r)) {
                    cols[j].erase(r);
                    rows[r].erase(j);
                    total--;
                }
            }
            
            // Check right
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int j = *it;
                if (cols[j].count(r)) {
                    cols[j].erase(r);
                    rows[r].erase(j);
                    total--;
                }
            }
        }
    }
    
    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}