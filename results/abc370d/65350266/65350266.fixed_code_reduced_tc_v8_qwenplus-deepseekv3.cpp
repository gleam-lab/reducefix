#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    rep(i, h) rep(j, w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Search up (previous in column)
            auto it_up = tate[c].lower_bound(r);
            if (it_up != tate[c].begin()) {
                --it_up;
                int tmp = *it_up;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }
            
            // Search down (next in column)
            auto it_down = tate[c].lower_bound(r);
            if (it_down != tate[c].end()) {
                int tmp = *it_down;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }
            
            // Search left (previous in row)
            auto it_left = yoko[r].lower_bound(c);
            if (it_left != yoko[r].begin()) {
                --it_left;
                int tmp = *it_left;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }
            
            // Search right (next in row)
            auto it_right = yoko[r].lower_bound(c);
            if (it_right != yoko[r].end()) {
                int tmp = *it_right;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }
        }
    }
    
    int ans = 0;
    rep(i, w) {
        ans += tate[i].size();
    }
    cout << ans << "\n";
    return 0;
}