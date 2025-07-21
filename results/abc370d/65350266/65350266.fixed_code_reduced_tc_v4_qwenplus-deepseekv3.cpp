#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w + 1), yoko(h + 1);
    
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Up
            auto it_up = tate[c].lower_bound(r);
            if (it_up != tate[c].begin()) {
                --it_up;
                int i = *it_up;
                tate[c].erase(i);
                yoko[i].erase(c);
            }
            
            // Down
            auto it_down = tate[c].lower_bound(r);
            if (it_down != tate[c].end()) {
                int i = *it_down;
                tate[c].erase(i);
                yoko[i].erase(c);
            }
            
            // Left
            auto it_left = yoko[r].lower_bound(c);
            if (it_left != yoko[r].begin()) {
                --it_left;
                int j = *it_left;
                yoko[r].erase(j);
                tate[j].erase(r);
            }
            
            // Right
            auto it_right = yoko[r].lower_bound(c);
            if (it_right != yoko[r].end()) {
                int j = *it_right;
                yoko[r].erase(j);
                tate[j].erase(r);
            }
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= w; j++) {
        ans += tate[j].size();
    }
    cout << ans << '\n';
    
    return 0;
}