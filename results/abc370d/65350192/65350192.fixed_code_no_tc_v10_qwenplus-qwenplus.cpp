#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);

    // Initialize all walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (rows[r].count(c)) {
            // Wall exists at the position: remove it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Look in each direction and remove nearest wall

            // Down direction
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int y = *it;
                cols[c].erase(it);
                rows[y].erase(c);
            }

            // Up direction
            it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int y = *it;
                cols[c].erase(it);
                rows[y].erase(c);
            }

            // Right direction
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].end()) {
                int x = *jt;
                rows[r].erase(jt);
                cols[x].erase(r);
            }

            // Left direction
            jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                --jt;
                int x = *jt;
                rows[r].erase(jt);
                cols[x].erase(r);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << endl;
    return 0;
}