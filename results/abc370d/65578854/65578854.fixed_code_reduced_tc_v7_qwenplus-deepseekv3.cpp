#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row_walls(H), col_walls(W);
    rep(i, H) rep(j, W) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    ll total_walls = (ll)H * W;
    ll destroyed = 0;

    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            destroyed++;
            continue;
        }

        // Up
        auto it = col_walls[C].lower_bound(R);
        if (it != col_walls[C].begin()) {
            --it;
            int r = *it;
            if (row_walls[r].count(C)) {
                row_walls[r].erase(C);
                col_walls[C].erase(r);
                destroyed++;
            }
            ++it;
        }

        // Down
        it = col_walls[C].lower_bound(R);
        if (it != col_walls[C].end()) {
            int r = *it;
            if (row_walls[r].count(C)) {
                row_walls[r].erase(C);
                col_walls[C].erase(r);
                destroyed++;
            }
        }

        // Left
        auto jt = row_walls[R].lower_bound(C);
        if (jt != row_walls[R].begin()) {
            --jt;
            int c = *jt;
            if (col_walls[c].count(R)) {
                col_walls[c].erase(R);
                row_walls[R].erase(c);
                destroyed++;
            }
            ++jt;
        }

        // Right
        jt = row_walls[R].lower_bound(C);
        if (jt != row_walls[R].end()) {
            int c = *jt;
            if (col_walls[c].count(R)) {
                col_walls[c].erase(R);
                row_walls[R].erase(c);
                destroyed++;
            }
        }
    }

    cout << total_walls - destroyed << endl;
    return 0;
}