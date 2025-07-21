#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 2), col_walls(W + 2);
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
        
        if (!row_walls[R].count(C)) {
            // Wall is present, destroy it
            row_walls[R].insert(C);
            col_walls[C].insert(R);
            --remaining;
        } else {
            // No wall, destroy the first in each direction
            // Up
            auto it_up = col_walls[C].upper_bound(R);
            int up = *it_up;
            if (up != H + 1 && !row_walls[up].count(C)) {
                row_walls[up].insert(C);
                col_walls[C].insert(up);
                --remaining;
            }
            // Down
            it_up = col_walls[C].lower_bound(R);
            --it_up;
            int down = *it_up;
            if (down != 0 && !row_walls[down].count(C)) {
                row_walls[down].insert(C);
                col_walls[C].insert(down);
                --remaining;
            }
            // Left
            auto it_left = row_walls[R].upper_bound(C);
            int left = *it_left;
            if (left != W + 1 && !col_walls[left].count(R)) {
                col_walls[left].insert(R);
                row_walls[R].insert(left);
                --remaining;
            }
            // Right
            it_left = row_walls[R].lower_bound(C);
            --it_left;
            int right = *it_left;
            if (right != 0 && !col_walls[right].count(R)) {
                col_walls[right].insert(R);
                row_walls[R].insert(right);
                --remaining;
            }
        }
    }

    cout << remaining << '\n';

    return 0;
}