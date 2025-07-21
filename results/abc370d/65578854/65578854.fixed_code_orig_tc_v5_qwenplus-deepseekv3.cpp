#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 2), col_walls(W + 2);
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    ll total_walls = (ll)H * W;
    ll destroyed = 0;

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;

        bool found = row_walls[R].count(C);
        if (found) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            destroyed++;
        } else {
            // Check up
            auto it = col_walls[C].lower_bound(R);
            if (it != col_walls[C].begin()) {
                --it;
                if (*it >= 1) {
                    row_walls[*it].erase(C);
                    col_walls[C].erase(it);
                    destroyed++;
                }
            }

            // Check down
            it = col_walls[C].lower_bound(R);
            if (it != col_walls[C].end()) {
                if (*it <= H) {
                    row_walls[*it].erase(C);
                    col_walls[C].erase(it);
                    destroyed++;
                }
            }

            // Check left
            it = row_walls[R].lower_bound(C);
            if (it != row_walls[R].begin()) {
                --it;
                if (*it >= 1) {
                    col_walls[*it].erase(R);
                    row_walls[R].erase(it);
                    destroyed++;
                }
            }

            // Check right
            it = row_walls[R].lower_bound(C);
            if (it != row_walls[R].end()) {
                if (*it <= W) {
                    col_walls[*it].erase(R);
                    row_walls[R].erase(it);
                    destroyed++;
                }
            }
        }
    }

    cout << total_walls - destroyed << endl;
    return 0;
}