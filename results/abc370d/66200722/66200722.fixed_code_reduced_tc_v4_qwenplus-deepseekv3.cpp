#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 2);
    vector<set<int>> col_walls(W + 2);
    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }

    long long remaining = (long long)H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            remaining++;
        } else {
            // Check up
            auto it = col_walls[C].lower_bound(R);
            --it;
            int up = *it;
            if (up >= 1 && up <= H && row_walls[up].count(C)) {
                row_walls[up].erase(C);
                col_walls[C].erase(up);
                remaining++;
            }

            // Check down
            it = col_walls[C].upper_bound(R);
            int down = *it;
            if (down >= 1 && down <= H && row_walls[down].count(C)) {
                row_walls[down].erase(C);
                col_walls[C].erase(down);
                remaining++;
            }

            // Check left
            it = row_walls[R].lower_bound(C);
            --it;
            int left = *it;
            if (left >= 1 && left <= W && col_walls[left].count(R)) {
                row_walls[R].erase(left);
                col_walls[left].erase(R);
                remaining++;
            }

            // Check right
            it = row_walls[R].upper_bound(C);
            int right = *it;
            if (right >= 1 && right <= W && col_walls[right].count(R)) {
                row_walls[R].erase(right);
                col_walls[right].erase(R);
                remaining++;
            }
        }
    }

    cout << remaining << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}