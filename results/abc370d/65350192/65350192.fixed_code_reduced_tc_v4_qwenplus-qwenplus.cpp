#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    
    // Initialize each cell with walls
    rep(i,h) rep(j,w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }
    
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (tate[c].count(r)) {  // Wall exists at the cell
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Up direction (same column, less than row)
            auto up = tate[c].lower_bound(r);
            if (up != tate[c].begin()) {
                up--;
                int u = *up;
                tate[c].erase(u);
                yoko[u].erase(c);
            }

            // Down direction (same column, greater than row)
            auto down = tate[c].lower_bound(r);
            if (down != tate[c].end()) {
                int d = *down;
                tate[c].erase(d);
                yoko[d].erase(c);
            }

            // Left direction (same row, less than column)
            auto left = yoko[r].lower_bound(c);
            if (left != yoko[r].begin()) {
                left--;
                int l = *left;
                yoko[r].erase(l);
                tate[l].erase(r);
            }

            // Right direction (same row, greater than column)
            auto right = yoko[r].lower_bound(c);
            if (right != yoko[r].end()) {
                int ri = *right;
                yoko[r].erase(ri);
                tate[ri].erase(r);
            }
        }
    }
    
    ll remaining = 0;
    rep(i,w) remaining += tate[i].size();
    cout << remaining << endl;
    
    return 0;
}