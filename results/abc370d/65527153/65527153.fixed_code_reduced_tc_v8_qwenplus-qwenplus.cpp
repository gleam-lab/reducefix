#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
void print(T val) {
    cout << val << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row, maintain a set of columns that still have walls
    vector<set<int>> rowWalls(H + 1);
    // For each column, maintain a set of rows that still have walls
    vector<set<int>> colWalls(W + 1);

    // Initialize all walls present
    for (int r = 1; r <= H; ++r) {
        for (int c = 1; c <= W; ++c) {
            rowWalls[r].insert(c);
            colWalls[c].insert(r);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;

        // If there's a wall at (R, C), destroy it
        if (rowWalls[R].count(C)) {
            rowWalls[R].erase(C);
            colWalls[C].erase(R);
        } else {
            // Otherwise, destroy first wall in each direction

            // Right in row R
            auto right = rowWalls[R].upper_bound(C);
            if (right != rowWalls[R].end()) {
                int c = *right;
                rowWalls[R].erase(c);
                colWalls[c].erase(R);
            }

            // Left in row R
            auto left = rowWalls[R].lower_bound(C);
            if (left != rowWalls[R].begin()) {
                --left;
                int c = *left;
                rowWalls[R].erase(c);
                colWalls[c].erase(R);
            }

            // Down in column C
            auto down = colWalls[C].upper_bound(R);
            if (down != colWalls[C].end()) {
                int r = *down;
                colWalls[C].erase(r);
                rowWalls[r].erase(C);
            }

            // Up in column C
            auto up = colWalls[C].lower_bound(R);
            if (up != colWalls[C].begin()) {
                --up;
                int r = *up;
                colWalls[C].erase(r);
                rowWalls[r].erase(C);
            }
        }
    }

    // Count remaining walls
    ll remaining = 0;
    for (int r = 1; r <= H; ++r) {
        remaining += rowWalls[r].size();
    }
    print(remaining);

    return 0;
}