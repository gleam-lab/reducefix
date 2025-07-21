#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(H + 2);  // For each row, stores columns with walls
    vector<set<int>> col(W + 2);  // For each column, stores rows with walls

    // Initialize with all walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    int remaining = H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row[R].count(C)) {
            // Cell has a wall, destroy it
            row[R].erase(C);
            col[C].erase(R);
            remaining--;
        } else {
            // Cell is empty, destroy first walls in four directions
            // Up
            auto it = col[C].lower_bound(R);
            if (it != col[C].begin()) {
                --it;
                row[*it].erase(C);
                col[C].erase(it);
                remaining--;
            }
            // Down
            it = col[C].upper_bound(R);
            if (it != col[C].end()) {
                row[*it].erase(C);
                col[C].erase(it);
                remaining--;
            }
            // Left
            it = row[R].lower_bound(C);
            if (it != row[R].begin()) {
                --it;
                col[*it].erase(R);
                row[R].erase(it);
                remaining--;
            }
            // Right
            it = row[R].upper_bound(C);
            if (it != row[R].end()) {
                col[*it].erase(R);
                row[R].erase(it);
                remaining--;
            }
        }
    }

    cout << remaining << endl;
    return 0;
}