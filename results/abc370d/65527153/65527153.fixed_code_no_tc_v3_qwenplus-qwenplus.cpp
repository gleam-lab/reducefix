#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 4e5 + 10;

int H, W, Q;
set<int> row[400010], col[400010];

// Function to remove a cell from its row and column sets
void erase(int r, int c) {
    row[r].erase(c);
    col[c].erase(r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> H >> W >> Q;

    // Initialize each row and column with all columns/rows (representing walls)
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row[r].find(c) != row[r].end()) {
            // Wall exists at the position, destroy it
            erase(r, c);
            continue;
        }

        // Look right
        auto it = row[r].lower_bound(c);
        if (it != row[r].end()) {
            erase(r, *it);
        }

        // Look left
        it = row[r].lower_bound(c);
        if (it != row[r].begin()) {
            --it;
            erase(r, *it);
        }

        // Look down
        auto it2 = col[c].lower_bound(r);
        if (it2 != col[c].end()) {
            erase(*it2, c);
        }

        // Look up
        it2 = col[c].lower_bound(r);
        if (it2 != col[c].begin()) {
            --it2;
            erase(*it2, c);
        }
    }

    // Count remaining walls
    ll ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += row[i].size();
    }
    cout << ans << '\n';

    return 0;
}