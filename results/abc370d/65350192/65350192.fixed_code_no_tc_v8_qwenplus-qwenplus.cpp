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
            // Wall already exists here - destroy it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Look in each direction and destroy the first wall found

            // Down
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int x = *it;
                rows[x].erase(c);
                cols[c].erase(x);
            }

            // Up
            it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int x = *it;
                rows[x].erase(c);
                cols[c].erase(x);
            }

            // Right
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int y = *it;
                cols[y].erase(r);
                rows[r].erase(y);
            }

            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                int y = *it;
                cols[y].erase(r);
                rows[r].erase(y);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i)
        ans += rows[i].size();
    cout << ans << "\n";

    return 0;
}