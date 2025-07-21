#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> rows(H + 2);
    vector<set<int>> cols(W + 2);
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    int ans = H * W;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        auto it_row = rows[R].find(C);
        if (it_row != rows[R].end()) {
            rows[R].erase(it_row);
            cols[C].erase(R);
            ans--;
        } else {
            // Up
            auto it_col = cols[C].lower_bound(R);
            if (it_col != cols[C].begin()) {
                --it_col;
                int r = *it_col;
                auto it = rows[r].find(C);
                if (it != rows[r].end()) {
                    rows[r].erase(it);
                    cols[C].erase(r);
                    ans--;
                }
            }
            
            // Down
            it_col = cols[C].lower_bound(R);
            if (it_col != cols[C].end()) {
                int r = *it_col;
                auto it = rows[r].find(C);
                if (it != rows[r].end()) {
                    rows[r].erase(it);
                    cols[C].erase(r);
                    ans--;
                }
            }
            
            // Left
            auto it_row_l = rows[R].lower_bound(C);
            if (it_row_l != rows[R].begin()) {
                --it_row_l;
                int c = *it_row_l;
                auto it = cols[c].find(R);
                if (it != cols[c].end()) {
                    cols[c].erase(it);
                    rows[R].erase(c);
                    ans--;
                }
            }
            
            // Right
            it_row_l = rows[R].lower_bound(C);
            if (it_row_l != rows[R].end()) {
                int c = *it_row_l;
                auto it = cols[c].find(R);
                if (it != cols[c].end()) {
                    cols[c].erase(it);
                    rows[R].erase(c);
                    ans--;
                }
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}