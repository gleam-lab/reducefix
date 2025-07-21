#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // For each row and column, maintain the positions of walls in ordered sets
    vector<set<int>> row(h), col(w);
    
    // Initialize all cells with walls
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r].count(c)) {
            // Wall exists at this cell: remove it
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Look up
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                col[c].erase(it);
                row[*it].erase(c);
            }

            // Look down
            it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                col[c].erase(it);
                row[*it].erase(c);
            }

            // Look left
            auto jt = row[r].lower_bound(c);
            if (jt != row[r].begin()) {
                --jt;
                row[r].erase(jt);
                col[*jt].erase(r);
            }

            // Look right
            jt = row[r].lower_bound(c);
            if (jt != row[r].end()) {
                row[r].erase(jt);
                col[*jt].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i)
        ans += col[i].size();

    cout << ans << endl;
    return 0;
}