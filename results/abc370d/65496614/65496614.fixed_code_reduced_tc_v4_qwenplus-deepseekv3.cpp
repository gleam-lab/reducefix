#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row_walls(h + 2);
    vector<set<int>> col_walls(w + 2);

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    int total_walls = h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            total_walls--;
        } else {
            auto it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                int j = *it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                total_walls--;
                it = row_walls[r].lower_bound(c);
            }
            it = row_walls[r].upper_bound(c);
            if (it != row_walls[r].end()) {
                int j = *it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                total_walls--;
            }

            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                int i = *it;
                col_walls[c].erase(i);
                row_walls[i].erase(c);
                total_walls--;
                it = col_walls[c].lower_bound(r);
            }
            it = col_walls[c].upper_bound(r);
            if (it != col_walls[c].end()) {
                int i = *it;
                col_walls[c].erase(i);
                row_walls[i].erase(c);
                total_walls--;
            }
        }
    }

    cout << total_walls << '\n';

    return 0;
}