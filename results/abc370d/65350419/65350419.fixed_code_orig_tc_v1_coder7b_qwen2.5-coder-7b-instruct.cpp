#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    map<int, set<int>> tate(w), yoko(h);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert 1-based to 0-based index

        if (!tate[c].empty() && *tate[c].begin() <= r && *tate[c].rbegin() >= r) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            auto it_row = tate[c].upper_bound(r);
            if (it_row != tate[c].begin()) {
                --it_row;
                int prev_r = *it_row;
                tate[c].erase(prev_r);
                yoko[prev_r].erase(c);
            }

            it_row = tate[c].upper_bound(r);
            if (it_row != tate[c].end()) {
                int next_r = *it_row;
                tate[c].erase(next_r);
                yoko[next_r].erase(c);
            }

            auto it_col = yoko[r].upper_bound(c);
            if (it_col != yoko[r].begin()) {
                --it_col;
                int prev_c = *it_col;
                yoko[r].erase(prev_c);
                tate[prev_c].erase(r);
            }

            it_col = yoko[r].upper_bound(c);
            if (it_col != yoko[r].end()) {
                int next_c = *it_col;
                yoko[r].erase(next_c);
                tate[next_c].erase(r);
            }
        }
    }

    int ans = 0;
    for (const auto& col : tate) {
        ans += col.second.size();
    }
    cout << ans << "\n";

    return 0;
}