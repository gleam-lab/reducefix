#include <vector>
#include <set>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H + 2, vector<bool>(W + 2, true));
    vector<set<int>> rowWalls(H + 2);
    vector<set<int>> colWalls(W + 2);

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

        if (grid[R][C]) {
            grid[R][C] = false;
            rowWalls[R].erase(C);
            colWalls[C].erase(R);
            broken++;
        } else {
            // Up
            auto it = colWalls[C].lower_bound(R);
            if (it != colWalls[C].begin()) {
                --it;
                int i = *it;
                if (grid[i][C]) {
                    grid[i][C] = false;
                    rowWalls[i].erase(C);
                    colWalls[C].erase(i);
                    broken++;
                }
                ++it;
            }

            // Down
            it = colWalls[C].lower_bound(R);
            if (it != colWalls[C].end()) {
                int i = *it;
                if (grid[i][C]) {
                    grid[i][C] = false;
                    rowWalls[i].erase(C);
                    colWalls[C].erase(i);
                    broken++;
                }
            }

            // Left
            auto jt = rowWalls[R].lower_bound(C);
            if (jt != rowWalls[R].begin()) {
                --jt;
                int j = *jt;
                if (grid[R][j]) {
                    grid[R][j] = false;
                    rowWalls[R].erase(j);
                    colWalls[j].erase(R);
                    broken++;
                }
                ++jt;
            }

            // Right
            jt = rowWalls[R].lower_bound(C);
            if (jt != rowWalls[R].end()) {
                int j = *jt;
                if (grid[R][j]) {
                    grid[R][j] = false;
                    rowWalls[R].erase(j);
                    colWalls[j].erase(R);
                    broken++;
                }
            }
        }
    }

    cout << (H * W - broken) << endl;

    return 0;
}