#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    h++; w++; // make 1-based index easier

    vector<set<int>> row(w), col(h);
    for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        // Use 1-based indexing to simplify logic
        if (row[r].count(c)) {
            // Bomb placed on a cell with wall -> destroy it
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // No wall -> destroy first walls in each direction
            // Up, Down, Left, Right

            // Up
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                int x = *it;
                row[x].erase(c);
                col[c].erase(x);
            }

            // Down
            it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                int x = *it;
                row[x].erase(c);
                col[c].erase(x);
            }

            // Left
            auto it2 = row[r].lower_bound(c);
            if (it2 != row[r].begin()) {
                --it2;
                int y = *it2;
                col[y].erase(r);
                row[r].erase(y);
            }

            // Right
            it2 = row[r].lower_bound(c);
            if (it2 != row[r].end()) {
                int y = *it2;
                col[y].erase(r);
                row[r].erase(y);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i < h; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;
    return 0;
}