#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);

    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }

    ll total_walls = (ll)H * W;
    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            total_walls--;
        } else {
            // Up
            auto it = col_walls[C].lower_bound(R);
            it--;
            int up = *it;
            if (up != 0 && row_walls[up].count(C)) {
                row_walls[up].erase(C);
                col_walls[C].erase(up);
                total_walls--;
            }

            // Down
            it = col_walls[C].lower_bound(R);
            int down = *it;
            if (down != H + 1 && row_walls[down].count(C)) {
                row_walls[down].erase(C);
                col_walls[C].erase(down);
                total_walls--;
            }

            // Left
            it = row_walls[R].lower_bound(C);
            it--;
            int left = *it;
            if (left != 0 && col_walls[left].count(R)) {
                col_walls[left].erase(R);
                row_walls[R].erase(left);
                total_walls--;
            }

            // Right
            it = row_walls[R].lower_bound(C);
            int right = *it;
            if (right != W + 1 && col_walls[right].count(R)) {
                col_walls[right].erase(R);
                row_walls[R].erase(right);
                total_walls--;
            }
        }
    }

    cout << total_walls << '\n';
    return 0;
}