#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h + 2, vector<bool>(w + 2, true));
    vector<set<int>> rows(h + 2), cols(w + 2);

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (!grid[r][c]) {
            auto it_r = rows[r].lower_bound(c);
            if (it_r != begin(rows[r])) {
                --it_r;
                grid[*it_r][r] = true;
                rows[r].insert(*it_r);
                cols[*it_r].insert(r);
            }

            it_r = rows[r].upper_bound(c);
            if (it_r != end(rows[r])) {
                grid[*it_r][r] = true;
                rows[r].insert(*it_r);
                cols[*it_r].insert(r);
            }

            auto it_c = cols[c].lower_bound(r);
            if (it_c != begin(cols[c])) {
                --it_c;
                grid[r][*it_c] = true;
                cols[c].insert(*it_c);
                rows[*it_c].insert(c);
            }

            it_c = cols[c].upper_bound(r);
            if (it_c != end(cols[c])) {
                grid[r][*it_c] = true;
                cols[c].insert(*it_c);
                rows[*it_c].insert(c);
            }
        } else {
            grid[r][c] = false;
            rows[r].erase(c);
            cols[c].erase(r);
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ans += grid[i][j];
        }
    }

    cout << ans << '\n';
    return 0;
}