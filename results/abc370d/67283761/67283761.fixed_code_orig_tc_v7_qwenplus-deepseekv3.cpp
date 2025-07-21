#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rows(H + 2);
    vector<set<int>> cols(W + 2);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    int total = H * W;
    int broken = 0;

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;

        auto& row_set = rows[r];
        auto& col_set = cols[c];

        if (row_set.count(c)) {
            row_set.erase(c);
            col_set.erase(r);
            ++broken;
        } else {
            // Find nearest wall in each direction
            // Left
            auto it_left = row_set.lower_bound(c);
            if (it_left != row_set.begin()) {
                --it_left;
                int j = *it_left;
                if (rows[r].count(j)) {
                    rows[r].erase(j);
                    cols[j].erase(r);
                    ++broken;
                }
            }
            // Right
            auto it_right = row_set.upper_bound(c);
            if (it_right != row_set.end()) {
                int j = *it_right;
                if (rows[r].count(j)) {
                    rows[r].erase(j);
                    cols[j].erase(r);
                    ++broken;
                }
            }
            // Up
            auto it_up = col_set.lower_bound(r);
            if (it_up != col_set.begin()) {
                --it_up;
                int i = *it_up;
                if (cols[c].count(i)) {
                    cols[c].erase(i);
                    rows[i].erase(c);
                    ++broken;
                }
            }
            // Down
            auto it_down = col_set.upper_bound(r);
            if (it_down != col_set.end()) {
                int i = *it_down;
                if (cols[c].count(i)) {
                    cols[c].erase(i);
                    rows[i].erase(c);
                    ++broken;
                }
            }
        }
    }

    cout << total - broken << endl;

    return 0;
}