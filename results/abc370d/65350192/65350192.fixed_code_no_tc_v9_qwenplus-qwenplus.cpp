#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);

    // Initialize all walls present
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
            // Wall exists at the cell: destroy it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Wall does not exist: destroy first wall in each direction

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int x = *it;
                cols[c].erase(it);
                rows[x].erase(c);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int x = *it;
                cols[c].erase(it);
                rows[x].erase(c);
            }

            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                int y = *it;
                rows[r].erase(it);
                cols[y].erase(r);
            }

            // Right
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int y = *it;
                rows[r].erase(it);
                cols[y].erase(r);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i)
        ans += rows[i].size();
    cout << ans << endl;

    return 0;
}