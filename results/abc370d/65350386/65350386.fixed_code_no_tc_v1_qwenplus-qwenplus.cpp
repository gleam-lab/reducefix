#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row, keep track of remaining walls in that row
    vector<set<int>> rows(H), cols(W);

    // Initially, all cells have walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at the position, remove it
        if (rows[R].count(C)) {
            rows[R].erase(C);
            cols[C].erase(R);
        } else {
            // Look up
            auto u = cols[C].lower_bound(R);
            if (u != cols[C].begin()) {
                u--;
                int cell = *u;
                cols[C].erase(cell);
                rows[cell].erase(C);
            }

            // Look down
            auto d = cols[C].lower_bound(R);
            if (d != cols[C].end()) {
                int cell = *d;
                cols[C].erase(cell);
                rows[cell].erase(C);
            }

            // Look left
            auto l = rows[R].lower_bound(C);
            if (l != rows[R].begin()) {
                l--;
                int cell = *l;
                rows[R].erase(cell);
                cols[cell].erase(R);
            }

            // Look right
            auto r = rows[R].lower_bound(C);
            if (r != rows[R].end()) {
                int cell = *r;
                rows[R].erase(cell);
                cols[cell].erase(R);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < W; ++i) {
        ans += cols[i].size();
    }
    cout << ans << endl;

    return 0;
}