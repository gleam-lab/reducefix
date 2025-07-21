#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rowWalls(H + 2);  // For each row, columns with walls (1-based)
    vector<set<int>> colWalls(W + 2);  // For each column, rows with walls (1-based)

    // Initialize all cells as having walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rowWalls[i].insert(j);
            colWalls[j].insert(i);
        }
    }

    int remaining = H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (rowWalls[R].count(C)) {
            // Cell has a wall, destroy it
            rowWalls[R].erase(C);
            colWalls[C].erase(R);
            remaining--;
        } else {
            // Cell is empty, destroy first walls in four directions
            // Up direction
            auto it = colWalls[C].lower_bound(R);
            if (it != colWalls[C].begin()) {
                --it;
                int r = *it;
                if (rowWalls[r].count(C)) {
                    rowWalls[r].erase(C);
                    colWalls[C].erase(r);
                    remaining--;
                }
                ++it;
            }

            // Down direction
            it = colWalls[C].lower_bound(R);
            if (it != colWalls[C].end()) {
                int r = *it;
                if (rowWalls[r].count(C)) {
                    rowWalls[r].erase(C);
                    colWalls[C].erase(r);
                    remaining--;
                }
            }

            // Left direction
            it = rowWalls[R].lower_bound(C);
            if (it != rowWalls[R].begin()) {
                --it;
                int c = *it;
                if (colWalls[c].count(R)) {
                    colWalls[c].erase(R);
                    rowWalls[R].erase(c);
                    remaining--;
                }
                ++it;
            }

            // Right direction
            it = rowWalls[R].lower_bound(C);
            if (it != rowWalls[R].end()) {
                int c = *it;
                if (colWalls[c].count(R)) {
                    colWalls[c].erase(R);
                    rowWalls[R].erase(c);
                    remaining--;
                }
            }
        }
    }

    cout << remaining << endl;
    return 0;
}