#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row(h + 2); // rows are 1..h, columns are 1..w
    vector<set<int>> col(w + 2);
    
    // Initialize all walls
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (row[r].count(c)) {
            // Wall exists at (r, c), destroy it
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // No wall at (r, c), destroy nearest walls in four directions
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                row[*it_up].erase(c);
                col[c].erase(it_up);
            }
            // Down
            it_up = col[c].lower_bound(r);
            if (it_up != col[c].end()) {
                row[*it_up].erase(c);
                col[c].erase(it_up);
            }
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                col[*it_left].erase(r);
                row[r].erase(it_left);
            }
            // Right
            it_left = row[r].lower_bound(c);
            if (it_left != row[r].end()) {
                col[*it_left].erase(r);
                row[r].erase(it_left);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        ans += row[i].size();
    }
    
    cout << ans << '\n';
    return 0;
}