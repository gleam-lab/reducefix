#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void update(int idx, int l, int r, int val) {
        if (l <= idx && r >= idx) {
            tree[idx] += val;
        } else {
            if (l <= n && r >= n) {
                update(2 * idx, l, r, val);
                update(2 * idx + 1, l, r, val);
                tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            } else if (l <= n) {
                update(2 * idx, n, r, val);
            } else {
                update(2 * idx + 1, l, n, val);
            }
        }
    }

    int query(int idx) {
        return tree[idx];
    }
};

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Initialize segment trees for rows and columns
    vector<SegmentTree> tate(h + 1), yoko(w + 1);
    for (int i = 0; i <= h; i++) tate[i] = SegmentTree(w);
    for (int i = 0; i <= w; i++) yoko[i] = SegmentTree(h);

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if the cell has a wall
        if (tate[r][c] == 0) {
            // Remove the wall
            tate[r][c] = 1;
            yoko[c][r] = 1;
        } else {
            // Find and remove surrounding walls
            // Implementation of this part needs careful management of segment trees
        }
    }

    // Calculate the number of remaining walls
    int remaining_walls = 0;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            remaining_walls += tate[i][j] + yoko[j][i];
        }
    }
    cout << remaining_walls << endl;

    return 0;
}