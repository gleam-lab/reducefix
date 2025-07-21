#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);

    // Initialize all cells to have walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (rows[r].count(c)) {
            // Wall exists at (r,c), remove it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Look up in column c from row r upwards
            auto up = cols[c].lower_bound(r);
            if (up != cols[c].begin()) {
                --up;
                rows[*up].erase(c);
                cols[c].erase(up);
            }

            // Look down in column c from row r downwards
            auto down = cols[c].lower_bound(r);
            if (down != cols[c].end()) {
                rows[*down].erase(c);
                cols[c].erase(down);
            }

            // Look left in row r from column c leftwards
            auto left = rows[r].lower_bound(c);
            if (left != rows[r].begin()) {
                --left;
                cols[*left].erase(r);
                rows[r].erase(left);
            }

            // Look right in row r from column c rightwards
            auto right = rows[r].lower_bound(c);
            if (right != rows[r].end()) {
                cols[*right].erase(r);
                rows[r].erase(right);
            }
        }
    }

    // Count remaining walls
    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << endl;

    return 0;
}