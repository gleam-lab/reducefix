#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int n) : n(n), tree(n * 4, 0) {}

    void update(int idx, int val) {
        for (int i = idx + n; i > 0; i /= 2) {
            tree[i] += val;
        }
    }

    int query(int l, int r) {
        int res = 0;
        for (int i = l + n; i <= r + n; i *= 2) {
            res += tree[i];
        }
        return res;
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H, vector<int>(W, 1)); // 1 represents a wall
    vector<SegmentTree> row(H), col(W);

    for (int i = 0; i < H; ++i) {
        row[i] = SegmentTree(W);
    }
    for (int j = 0; j < W; ++j) {
        col[j] = SegmentTree(H);
    }

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there is a wall at (r, c)
        if (grid[r][c]) {
            grid[r][c] = 0;
            row[r].update(c, -1);
            col[c].update(r, -1);
        } else {
            // Find the first row above and below
            int above = -1, below = H;
            for (int i = r - 1; i >= 0; --i) {
                if (row[i].query(c, c) == 0) {
                    above = i;
                    break;
                }
            }
            for (int i = r + 1; i < H; ++i) {
                if (row[i].query(c, c) == 0) {
                    below = i;
                    break;
                }
            }

            // Update the segment trees
            for (int i = above + 1; i < below; ++i) {
                row[i].update(c, 1);
            }
            for (int j = c - 1; j >= 0; --j) {
                col[j].update(r, 1);
            }
            for (int j = c + 1; j < W; ++j) {
                col[j].update(r, 1);
            }
        }
    }

    int remainingwalls = 0;
    for (int i = 0; i < H; ++i) {
        remainingwalls += row[i].query(W - 1, W - 1);
    }
    for (int j = 0; j < W; ++j) {
        remainingwalls += col[j].query(H - 1, H - 1);
    }

    cout << remainingwalls << endl;
    return 0;
}