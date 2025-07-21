#include <vector>
#include <set>
#include <iostream>
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

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;

        if (rowWalls[R].count(C)) {
            rowWalls[R].erase(C);
            colWalls[C].erase(R);
            broken++;
        } else {
            // Left
            auto it_left = rowWalls[R].lower_bound(C);
            it_left--;
            int left = *it_left;
            if (left >= 1) {
                rowWalls[R].insert(left);
                colWalls[left].insert(R);
                broken--;
                rowWalls[R].erase(left);
                colWalls[left].erase(R);
                broken++;
            }

            // Right
            auto it_right = rowWalls[R].upper_bound(C);
            int right = *it_right;
            if (right <= W) {
                rowWalls[R].insert(right);
                colWalls[right].insert(R);
                broken--;
                rowWalls[R].erase(right);
                colWalls[right].erase(R);
                broken++;
            }

            // Up
            auto it_up = colWalls[C].lower_bound(R);
            it_up--;
            int up = *it_up;
            if (up >= 1) {
                colWalls[C].insert(up);
                rowWalls[up].insert(C);
                broken--;
                colWalls[C].erase(up);
                rowWalls[up].erase(C);
                broken++;
            }

            // Down
            auto it_down = colWalls[C].upper_bound(R);
            int down = *it_down;
            if (down <= H) {
                colWalls[C].insert(down);
                rowWalls[down].insert(C);
                broken--;
                colWalls[C].erase(down);
                rowWalls[down].erase(C);
                broken++;
            }
        }
    }

    cout << (H * W - broken) << endl;

    return 0;
}