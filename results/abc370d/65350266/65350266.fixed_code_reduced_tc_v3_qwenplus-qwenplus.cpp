#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    
    rep(i,h) rep(j,w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }

    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (tate[c].find(r) != tate[c].end()) {
            // Wall exists at the position, destroy it
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Up direction
            auto up = tate[c].lower_bound(r);
            if (up != tate[c].begin()) {
                up--;
                tate[c].erase(*up);
                yoko[*up].erase(c);
            }
            
            // Down direction
            auto down = tate[c].lower_bound(r);
            if (down != tate[c].end()) {
                tate[c].erase(*down);
                yoko[*down].erase(c);
            }
            
            // Left direction
            auto left = yoko[r].lower_bound(c);
            if (left != yoko[r].begin()) {
                left--;
                yoko[r].erase(*left);
                tate[*left].erase(r);
            }
            
            // Right direction
            auto right = yoko[r].lower_bound(c);
            if (right != yoko[r].end()) {
                yoko[r].erase(*right);
                tate[*right].erase(r);
            }
        }
    }

    int ans = 0;
    rep(i,w) ans += tate[i].size();
    cout << ans << "\n";
    
    return 0;
}