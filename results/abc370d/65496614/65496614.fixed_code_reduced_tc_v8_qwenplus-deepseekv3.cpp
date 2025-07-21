#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(h + 2);
    vector<set<int>> col(w + 2);

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    int ans = h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            ans--;
        } else {
            // Check up
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                int i = *it;
                row[i].erase(c);
                col[c].erase(it);
                ans--;
            }
            // Check down
            it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                int i = *it;
                row[i].erase(c);
                col[c].erase(it);
                ans--;
            }
            // Check left
            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                int j = *it;
                row[r].erase(it);
                col[j].erase(r);
                ans--;
            }
            // Check right
            it = row[r].lower_bound(c);
            if (it != row[r].end()) {
                int j = *it;
                row[r].erase(it);
                col[j].erase(r);
                ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}