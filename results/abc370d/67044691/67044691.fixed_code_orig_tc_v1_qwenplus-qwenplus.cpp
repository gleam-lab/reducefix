#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> P;

const int MAX = 2e5 + 10;

int H, W, Q;
set<int> row[4 * MAX];
set<int> col[4 * MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W >> Q;

    // Initialize sets for each row and column with all positions having walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        --R;
        --C;

        // Check if there is a wall at (R,C)
        auto it = row[R].find(C);
        if (it != row[R].end()) {
            // Destroy the wall at (R,C)
            row[R].erase(it);
            col[C].erase(R);
        } else {
            // Directions: up, down, left, right
            vector<P> to_destroy;

            // Up
            auto cit = col[C].lower_bound(R);
            if (cit != col[C].begin()) {
                --cit;
                to_destroy.push_back(P(*cit, C));
            }

            // Down
            cit = col[C].upper_bound(R);
            if (cit != col[C].end()) {
                to_destroy.push_back(P(*cit, C));
            }

            // Left
            auto rit = row[R].lower_bound(C);
            if (rit != row[R].begin()) {
                --rit;
                to_destroy.push_back(P(R, *rit));
            }

            // Right
            rit = row[R].upper_bound(C);
            if (rit != row[R].end()) {
                to_destroy.push_back(P(R, *rit));
            }

            // Remove walls in the found directions
            for (auto p : to_destroy) {
                int r = p.first, c = p.second;
                row[r].erase(c);
                col[c].erase(r);
            }
        }
    }

    // Count remaining walls
    ll ans = 0;
    for (int i = 0; i < H; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;

    return 0;
}