#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    
    // Initialize the sets with all positions
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (tate[c].count(r)) {  // Wall exists at the position
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {  // Wall doesn't exist, so destroy walls in four directions
            // Up and Down (column-wise operations on tate[c])
            auto it = tate[c].lower_bound(r);
            
            // Down - first element greater than r
            if (it != tate[c].end()) {
                int tmp = *it;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }

            // Up - last element less than r
            if (it != tate[c].begin()) {
                --it;
                int tmp = *it;
                tate[c].erase(tmp);
                yoko[tmp].erase(c);
            }

            // Left and Right (row-wise operations on yoko[r])
            auto it2 = yoko[r].lower_bound(c);
            
            // Right - first element greater than c
            if (it2 != yoko[r].end()) {
                int tmp = *it2;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }

            // Left - last element less than c
            if (it2 != yoko[r].begin()) {
                --it2;
                int tmp = *it2;
                yoko[r].erase(tmp);
                tate[tmp].erase(r);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += tate[i].size();
    }
    cout << ans << "\n";
    return 0;
}