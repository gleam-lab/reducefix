#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // tate[c]: set of rows in column c that still have walls
    vector<set<int>> tate(w);
    // yoko[r]: set of columns in row r that still have walls
    vector<set<int>> yoko(h);

    // Initialize all walls present
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
            // Wall exists at (r,c), destroy it
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Destroy first wall above
            auto it = tate[c].lower_bound(r);
            if (it != tate[c].begin()) {
                it--;
                int row = *it;
                tate[c].erase(row);
                yoko[row].erase(c);
            }

            // Destroy first wall below
            it = tate[c].lower_bound(r);
            if (it != tate[c].end()) {
                int row = *it;
                tate[c].erase(row);
                yoko[row].erase(c);
            }

            // Destroy first wall to the left
            auto jt = yoko[r].lower_bound(c);
            if (jt != yoko[r].begin()) {
                jt--;
                int col = *jt;
                yoko[r].erase(col);
                tate[col].erase(r);
            }

            // Destroy first wall to the right
            jt = yoko[r].lower_bound(c);
            if (jt != yoko[r].end()) {
                int col = *jt;
                yoko[r].erase(col);
                tate[col].erase(r);
            }
        }
    }

    // Count remaining walls
    long long ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += tate[i].size();
    }
    cout << ans << endl;

    return 0;
}