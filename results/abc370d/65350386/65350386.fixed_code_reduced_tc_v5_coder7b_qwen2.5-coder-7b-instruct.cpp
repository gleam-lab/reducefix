#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(w), cols(h);

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (rows[c].find(r) == rows[c].end() && cols[r].find(c) == cols[r].end()) {
            // Place a bomb and destroy walls
            rows[c].insert(r);
            cols[r].insert(c);
        } else if (rows[c].find(r) != rows[c].end()) {
            // Destroy the first wall above or below
            auto it = rows[c].upper_bound(r);
            if (it != rows[c].begin()) {
                --it;
                rows[c].erase(it);
                cols[*it].erase(c);
            }
        } else {
            // Destroy the first wall to the left or right
            auto it = cols[r].upper_bound(c);
            if (it != cols[r].begin()) {
                --it;
                cols[r].erase(it);
                rows[*it].erase(r);
            }
        }
    }

    int remaining_walls = 0;
    for (const auto& col : cols) {
        remaining_walls += col.size();
    }

    cout << remaining_walls << endl;
    return 0;
}