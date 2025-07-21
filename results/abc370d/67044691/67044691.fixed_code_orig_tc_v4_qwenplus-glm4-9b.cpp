#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(H), col(W);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        --R; --C; // Convert to 0-based index

        // Check if there's a wall at the given position
        if (!row[R].count(C)) {
            // No wall, destroy walls in all four directions
            int upwards = R;
            while (upwards > 0 && !row[upwards].count(C)) {
                row[upwards].erase(C);
                upwards--;
            }
            int downwards = R;
            while (downwards < H - 1 && !row[downwards].count(C)) {
                row[downwards].erase(C);
                downwards++;
            }
            int leftwards = C;
            while (leftwards > 0 && !col[leftwards].count(R)) {
                col[leftwards].erase(R);
                leftwards--;
            }
            int rightwards = C;
            while (rightwards < W - 1 && !col[rightwards].count(R)) {
                col[rightwards].erase(R);
                rightwards++;
            }
        } else {
            // Wall at the given position, remove it
            row[R].erase(C);
            col[C].erase(R);
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        remainingWalls += row[i].size();
    }
    for (int j = 0; j < W; ++j) {
        remainingWalls += col[j].size();
    }

    cout << remainingWalls << endl;
    return 0;
}