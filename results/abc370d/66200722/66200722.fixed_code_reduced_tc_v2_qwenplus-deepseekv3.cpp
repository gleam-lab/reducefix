#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row_walls(h + 2);
    vector<set<int>> col_walls(w + 2);
    for (int i = 1; i <= h; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(w + 1);
    }
    for (int j = 1; j <= w; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(h + 1);
    }

    long long remaining = h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining++;
        } else {
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            remaining--;

            auto it_up = col_walls[c].lower_bound(r);
            --it_up;
            if (*it_up != 0) {
                row_walls[*it_up].insert(c);
                col_walls[c].insert(*it_up);
                remaining--;
            }

            auto it_down = col_walls[c].upper_bound(r);
            if (*it_down != h + 1) {
                row_walls[*it_down].insert(c);
                col_walls[c].insert(*it_down);
                remaining--;
            }

            auto it_left = row_walls[r].lower_bound(c);
            --it_left;
            if (*it_left != 0) {
                row_walls[r].insert(*it_left);
                col_walls[*it_left].insert(r);
                remaining--;
            }

            auto it_right = row_walls[r].upper_bound(c);
            if (*it_right != w + 1) {
                row_walls[r].insert(*it_right);
                col_walls[*it_right].insert(r);
                remaining--;
            }
        }
    }

    cout << remaining << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}