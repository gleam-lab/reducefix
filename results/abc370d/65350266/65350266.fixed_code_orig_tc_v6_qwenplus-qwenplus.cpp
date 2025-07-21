#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // tate[j] stores the rows with walls in column j
    vector<set<int>> tate(w);
    // yoko[i] stores the columns with walls in row i
    vector<set<int>> yoko(h);

    // Initialize walls
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

        auto& col_set = tate[c];
        auto& row_set = yoko[r];

        if (col_set.find(r) != col_set.end()) {
            // Wall exists at (r, c)
            col_set.erase(r);
            row_set.erase(c);
        } else {
            // Destroy up (first wall above)
            auto it = col_set.lower_bound(r);
            if (it != col_set.begin()) {
                it--;
                int x = *it;
                col_set.erase(x);
                yoko[x].erase(c);
            }

            // Destroy down (first wall below)
            it = col_set.lower_bound(r);
            if (it != col_set.end()) {
                int x = *it;
                col_set.erase(x);
                yoko[x].erase(c);
            }

            // Destroy left (first wall to left)
            auto& rs = yoko[r];
            it = rs.lower_bound(c);
            if (it != rs.begin()) {
                it--;
                int y = *it;
                rs.erase(y);
                tate[y].erase(r);
            }

            // Destroy right (first wall to right)
            it = rs.lower_bound(c);
            if (it != rs.end()) {
                int y = *it;
                rs.erase(y);
                tate[y].erase(r);
            }
        }
    }

    int ans = 0;
    for (auto& s : tate) {
        ans += s.size();
    }
    cout << ans << endl;

    return 0;
}