#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(h + 2); // rows 1..h, columns 1..w
    vector<set<int>> col(w + 2); // columns 1..w, rows 1..h

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    int remaining = h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            remaining--;
        } else {
            // Check up
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                int i = *it;
                if (row[i].count(c)) {
                    row[i].erase(c);
                    col[c].erase(i);
                    remaining--;
                }
                ++it;
            }

            // Check down
            it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                int i = *it;
                if (row[i].count(c)) {
                    row[i].erase(c);
                    col[c].erase(i);
                    remaining--;
                }
            }

            // Check left
            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                int j = *it;
                if (col[j].count(r)) {
                    col[j].erase(r);
                    row[r].erase(j);
                    remaining--;
                }
                ++it;
            }

            // Check right
            it = row[r].lower_bound(c);
            if (it != row[r].end()) {
                int j = *it;
                if (col[j].count(r)) {
                    col[j].erase(r);
                    row[r].erase(j);
                    remaining--;
                }
            }
        }
    }

    cout << remaining << '\n';
    return 0;
}