#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(w), yoko(h);
    
    // Initialize each row and column with all wall positions
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
        
        if (tate[c].count(r)) {
            // Wall exists at the position, destroy it
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Look in all four directions and destroy first walls
            // Up and Down on the same column (tate)
            auto& colSet = tate[c];
            auto downIt = colSet.lower_bound(r);
            if (downIt != colSet.end()) { // Down direction
                int tmp = *downIt;
                colSet.erase(downIt);
                yoko[tmp].erase(c);
            }
            
            auto upIt = colSet.lower_bound(r);
            if (upIt != colSet.begin()) { // Up direction
                --upIt;
                int tmp = *upIt;
                colSet.erase(upIt);
                yoko[tmp].erase(c);
            }

            // Left and Right on the same row (yoko)
            auto& rowSet = yoko[r];
            auto rightIt = rowSet.lower_bound(c);
            if (rightIt != rowSet.end()) { // Right direction
                int tmp = *rightIt;
                rowSet.erase(rightIt);
                tate[tmp].erase(r);
            }
            
            auto leftIt = rowSet.lower_bound(c);
            if (leftIt != rowSet.begin()) { // Left direction
                --leftIt;
                int tmp = *leftIt;
                rowSet.erase(leftIt);
                tate[tmp].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += tate[i].size();
    }
    cout << ans << endl;
    
    return 0;
}