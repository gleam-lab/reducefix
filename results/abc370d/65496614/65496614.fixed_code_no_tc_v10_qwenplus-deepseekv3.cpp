#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(h + 2);
    vector<set<int>> col(w + 2);

    // Initialize sets with all possible positions
    for (int i = 1; i <= h; ++i) {
        row[i].insert(0);
        row[i].insert(w + 1);
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
        }
    }
    for (int j = 1; j <= w; ++j) {
        col[j].insert(0);
        col[j].insert(h + 1);
        for (int i = 1; i <= h; ++i) {
            col[j].insert(i);
        }
    }

    int r, c;
    long long remaining = (long long)h * w;

    while (q--) {
        cin >> r >> c;

        if (row[r].count(c)) {
            // Case 1: Wall exists at (r, c)
            row[r].erase(c);
            col[c].erase(r);
            remaining--;
        } else {
            // Case 2: Wall doesn't exist at (r, c)
            // Look up
            auto it = col[c].lower_bound(r);
            --it;
            if (*it != 0) {
                row[*it].erase(c);
                col[c].erase(*it);
                remaining--;
            }
            // Look down
            it = col[c].upper_bound(r);
            if (*it != h + 1) {
                row[*it].erase(c);
                col[c].erase(*it);
                remaining--;
            }
            // Look left
            it = row[r].lower_bound(c);
            --it;
            if (*it != 0) {
                col[*it].erase(r);
                row[r].erase(*it);
                remaining--;
            }
            // Look right
            it = row[r].upper_bound(c);
            if (*it != w + 1) {
                col[*it].erase(r);
                row[r].erase(*it);
                remaining--;
            }
        }
    }

    cout << remaining << endl;
    return 0;
}