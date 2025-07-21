#include <vector>
#include <set>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rowWalls(H + 2); // Rows 1..H, columns 1..W
    vector<set<int>> colWalls(W + 2); // Columns 1..W, rows 1..H

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rowWalls[i].insert(j);
            colWalls[j].insert(i);
        }
    }

    int broken = 0;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (rowWalls[R].count(C)) {
            rowWalls[R].erase(C);
            colWalls[C].erase(R);
            broken++;
        } else {
            // Check up
            auto it = colWalls[C].lower_bound(R);
            if (it != colWalls[C].begin()) {
                --it;
                int i = *it;
                if (rowWalls[i].count(C)) {
                    rowWalls[i].erase(C);
                    colWalls[C].erase(i);
                    broken++;
                }
            }

            // Check down
            it = colWalls[C].upper_bound(R);
            if (it != colWalls[C].end()) {
                int i = *it;
                if (rowWalls[i].count(C)) {
                    rowWalls[i].erase(C);
                    colWalls[C].erase(i);
                    broken++;
                }
            }

            // Check left
            it = rowWalls[R].lower_bound(C);
            if (it != rowWalls[R].begin()) {
                --it;
                int j = *it;
                if (colWalls[j].count(R)) {
                    colWalls[j].erase(R);
                    rowWalls[R].erase(j);
                    broken++;
                }
            }

            // Check right
            it = rowWalls[R].upper_bound(C);
            if (it != rowWalls[R].end()) {
                int j = *it;
                if (colWalls[j].count(R)) {
                    colWalls[j].erase(R);
                    rowWalls[R].erase(j);
                    broken++;
                }
            }
        }
    }

    cout << H * W - broken << '\n';

    return 0;
}