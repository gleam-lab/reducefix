#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(h), yoko(w);
    rep(i, h) rep(j, w) {
        tate[i].insert(j);
        yoko[j].insert(i);
    }
    
    rep(q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        // Remove the wall if it exists at (r, c)
        tate[r].erase(c);
        yoko[c].erase(r);
        
        // Find the next wall above
        if (auto it = tate[r].lower_bound(c); it != tate[r].begin()) {
            --it;
            int above = *it;
            tate[r].erase(above);
            yoko[above].erase(r);
        }
        
        // Find the next wall below
        if (auto it = tate[r].lower_bound(c); it != tate[r].end()) {
            int below = *it;
            tate[r].erase(below);
            yoko[below].erase(r);
        }
        
        // Find the next wall to the left
        if (auto it = yoko[c].lower_bound(r); it != yoko[c].begin()) {
            --it;
            int left = *it;
            yoko[c].erase(left);
            tate[left].erase(c);
        }
        
        // Find the next wall to the right
        if (auto it = yoko[c].lower_bound(r); it != yoko[c].end()) {
            int right = *it;
            yoko[c].erase(right);
            tate[right].erase(c);
        }
    }
    
    ll ans = 0;
    rep(i, h) rep(j, w) {
        ans += tate[i].size();
    }
    cout << ans << "\n";
    return 0;
}