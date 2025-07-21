#include <bits/stdc++.h>
using namespace std;

// Segment tree data structure
struct SegTree {
    vector<int> tree;
    int n;
    function<int(int, int)> join;
    function<int(int, int)> merge;

    // Constructor
    SegTree(int n, function<int(int, int)> join, function<int(int, int)> merge)
        : n(n), join(join), merge(merge) {
        tree.assign(4 * n, 1);
    }

    // Build the tree
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 1;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // Update a range of elements
    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Get the sum of a range of elements
    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return join(left, right);
    }
};

// Main function
int main() {
    // Your implementation here
}