#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2 * 1e5 + 5; // Maximum number of elements including extra space for segment tree
const int INF = INT_MAX;

struct SegmentTree {
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int size) : tree(4 * size, 0), lazy(4 * size, 0) {}

    void updateRange(int node, int start, int end, int L, int R, int value) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (R < start || L > end) {
            return;
        }
        if (L <= start && end <= R) {
            tree[node] += (end - start + 1) * value;
            if (start != end) {
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, L, R, value);
        updateRange(node * 2 + 1, mid + 1, end, L, R, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int querySum(int node, int start, int end, int pos) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start == end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        if (pos <= mid) {
            return querySum(node * 2, start, mid, pos);
        } else {
            return querySum(node * 2 + 1, mid + 1, end, pos);
        }
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize the segment tree
    SegmentTree tree(W + 1);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            // Initially, all cells have a wall
            tree.updateRange(1, 0, W, 0, W, 1);
        }
    }

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r;
        --c;

        // Check if there's a wall at (r, c)
        if (tree.querySum(1, 0, W, c) == 0) {
            // There's no wall at (r, c), so we need to destroy walls in all four directions
            // This part of the code needs to be implemented
        } else {
            // There's a wall at (r, c), destroy it
            tree.updateRange(1, 0, W, c, c, -1);
        }
    }

    // Count the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i <= W; ++i) {
        remainingWalls += tree.querySum(1, 0, W, i);
    }
    cout << remainingWalls << endl;

    return 0;
}