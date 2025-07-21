#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rowWalls(H + 1);
    vector<set<int>> colWalls(W + 1);

    for (int i = 1; i <= H; ++i) {
        rowWalls[i].insert(0);
        rowWalls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        colWalls[j].insert(0);
        colWalls[j].insert(H + 1);
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
            // Left
            auto it = rowWalls[R].lower_bound(C);
            --it;
            int left = *it;
            if (left != 0) {
                rowWalls[R].erase(left);
                colWalls[left].erase(R);
                broken++;
            }

            // Right
            it = rowWalls[R].upper_bound(C);
            int right = *it;
            if (right != W + 1) {
                rowWalls[R].erase(right);
                colWalls[right].erase(R);
                broken++;
            }

            // Up
            it = colWalls[C].lower_bound(R);
            --it;
            int up = *it;
            if (up != 0) {
                colWalls[C].erase(up);
                rowWalls[up].erase(C);
                broken++;
            }

            // Down
            it = colWalls[C].upper_bound(R);
            int down = *it;
            if (down != H + 1) {
                colWalls[C].erase(down);
                rowWalls[down].erase(C);
                broken++;
            }
        }
    }

    cout << H * W - broken << '\n';

    return 0;
}