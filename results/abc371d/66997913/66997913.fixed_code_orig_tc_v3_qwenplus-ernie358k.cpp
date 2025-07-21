#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005; // Maximum possible value of n + some extra for safety

struct SegmentTree {
    vector<ll> tree;
    vector<int> lazy;
    int n;

    SegmentTree(int _n) : n(_n) {
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void updateRange(int L, int R, int delta) {
        // Fill this function
    }

    ll queryRange(int L, int R) {
        // Fill this function
        return 0;
    }

    void build(const vector<ll>& arr, int node = 1, int start = 0, int end = 0) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    
    SegmentTree segTree(n);
    // Build the segment tree based on some transformation of p
    // Fill this part
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Use segTree to find the sum of p values where x values are in range [l, r]
        // Fill this part
    }
    return 0;
}