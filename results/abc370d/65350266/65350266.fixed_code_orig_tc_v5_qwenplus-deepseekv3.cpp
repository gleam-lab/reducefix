#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h), col_walls(w);
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    
    int remaining = h * w;
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int u = *it_up;
                if (row_walls[u].count(c)) {
                    row_walls[u].erase(c);
                    col_walls[c].erase(u);
                    remaining--;
                }
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int d = *it_down;
                if (row_walls[d].count(c)) {
                    row_walls[d].erase(c);
                    col_walls[c].erase(d);
                    remaining--;
                }
            }
            
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int l = *it_left;
                if (col_walls[l].count(r)) {
                    col_walls[l].erase(r);
                    row_walls[r].erase(l);
                    remaining--;
                }
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int ri = *it_right;
                if (col_walls[ri].count(r)) {
                    col_walls[ri].erase(r);
                    row_walls[r].erase(ri);
                    remaining--;
                }
            }
        }
    }
    
    cout << remaining << endl;
    return 0;
}