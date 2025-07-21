#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_set(h+1);  // 1-based for rows
    vector<set<int>> col_set(w+1);  // 1-based for cols
    
    // Initialize with all walls present
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            row_set[i].insert(j);
            col_set[j].insert(i);
        }
    }
    
    int remaining = h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_set[r].count(c)) {
            // Wall exists - destroy it
            row_set[r].erase(c);
            col_set[c].erase(r);
            remaining--;
        } else {
            // No wall - find first walls in 4 directions
            
            // Up
            auto it_up = col_set[c].lower_bound(r);
            if (it_up != col_set[c].begin()) {
                --it_up;
                int i = *it_up;
                row_set[i].erase(c);
                col_set[c].erase(i);
                remaining--;
            }
            
            // Down
            auto it_down = col_set[c].lower_bound(r);
            if (it_down != col_set[c].end()) {
                int i = *it_down;
                row_set[i].erase(c);
                col_set[c].erase(i);
                remaining--;
            }
            
            // Left
            auto it_left = row_set[r].lower_bound(c);
            if (it_left != row_set[r].begin()) {
                --it_left;
                int j = *it_left;
                row_set[r].erase(j);
                col_set[j].erase(r);
                remaining--;
            }
            
            // Right
            auto it_right = row_set[r].lower_bound(c);
            if (it_right != row_set[r].end()) {
                int j = *it_right;
                row_set[r].erase(j);
                col_set[j].erase(r);
                remaining--;
            }
        }
    }
    
    cout << remaining << "\n";
    return 0;
}