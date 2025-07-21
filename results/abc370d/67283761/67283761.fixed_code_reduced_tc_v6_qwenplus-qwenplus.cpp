#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row and column, maintain the positions of walls as a sorted set
    vector<set<int>> rows(H), cols(W);

    // Initially, all cells have walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // Check if there is a wall at (R, C)
        auto it = rows[R].find(C);
        if (it != rows[R].end()) {
            // Wall exists, remove it from both sets
            rows[R].erase(it);
            cols[C].erase(R);
        } else {
            // Wall does not exist, find first walls in each direction
            int directions[4];

            // Left
            auto left = rows[R].lower_bound(C);
            if (left != rows[R].begin()) {
                left--;
                directions[0] = *left;
            } else {
                directions[0] = -1;
            }

            // Right
            auto right = rows[R].upper_bound(C);
            if (right != rows[R].end()) {
                directions[1] = *right;
            } else {
                directions[1] = -1;
            }

            // Up
            auto up = cols[C].lower_bound(R);
            if (up != cols[C].begin()) {
                up--;
                directions[2] = *up;
            } else {
                directions[2] = -1;
            }

            // Down
            auto down = cols[C].upper_bound(R);
            if (down != cols[C].end()) {
                directions[3] = *down;
            } else {
                directions[3] = -1;
            }

            // Remove walls found in each direction
            for (int i = 0; i < 4; ++i) {
                if (directions[i] == -1) continue;
                if (i < 2) { // Horizontal directions: left or right
                    int y = R, x = directions[i];
                    rows[y].erase(x);
                    cols[x].erase(y);
                } else { // Vertical directions: up or down
                    int y = directions[i], x = C;
                    rows[y].erase(x);
                    cols[x].erase(y);
                }
            }
        }
    }

    // Count remaining walls
    long long remaining = 0;
    for (int i = 0; i < H; ++i) {
        remaining += rows[i].size();
    }
    cout << remaining << endl;

    return 0;
}