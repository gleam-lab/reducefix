#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for(int i = s; i < (int)(n); ++i)

int H, W, Q;
vector<set<int>> row_sets, col_sets;

// Destroy wall at (r, c)
void destroy(int r, int c) {
    row_sets[r].erase(c);
    col_sets[c].erase(r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> H >> W >> Q;
    row_sets.resize(H);
    col_sets.resize(W);

    // Initialize all walls
    rep(r, H) {
        rep(c, W) {
            row_sets[r].insert(c);
            col_sets[c].insert(r);
        }
    }

    rep(q, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        auto& cols = row_sets[R];
        auto& rows = col_sets[C];

        if (cols.find(C) != cols.end()) {
            // Wall already exists at (R, C)
            destroy(R, C);
        } else {
            // Look up
            auto it = rows.lower_bound(R);
            if (it != rows.begin()) {
                --it;
                destroy(*it, C);
            }

            // Look down
            it = rows.lower_bound(R);
            if (it != rows.end()) {
                destroy(*it, C);
            }

            // Look left
            auto& rc_set = row_sets[R];
            auto jt = rc_set.lower_bound(C);
            if (jt != rc_set.begin()) {
                --jt;
                destroy(R, *jt);
            }

            // Look right
            jt = rc_set.lower_bound(C);
            if (jt != rc_set.end()) {
                destroy(R, *jt);
            }
        }
    }

    // Count remaining walls
    long long ans = 0;
    rep(r, H) ans += row_sets[r].size();
    cout << ans << "\n";

    return 0;
}