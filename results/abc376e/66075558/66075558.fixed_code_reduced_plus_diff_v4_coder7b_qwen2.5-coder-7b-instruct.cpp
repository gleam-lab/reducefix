#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

typedef long long ll;

struct Node {
    ll sum;
    ll max_val;
    Node(ll _sum = 0, ll _max_val = 0) : sum(_sum), max_val(_max_val) {}
};

class SegmentTree {
public:
    vector<Node> tree;
    int n;

    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n);
    }

    void build(vector<ll>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {arr[tl], arr[tl]};
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return {0, -1};
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        Node left = query(v * 2, tl, tm, l, min(r, tm));
        Node right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return merge(left, right);
    }

private:
    Node merge(Node a, Node b) {
        return {a.sum + b.sum, max(a.max_val, b.max_val)};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        // Sort indices based on A values
        vector<pair<ll, int>> idx(n);
        for (int i = 0; i < n; ++i) {
            idx[i] = {A[i], i};
        }
        sort(idx.begin(), idx.end());
        
        // Initialize segment tree for sums of B values
        SegmentTree st(n);
        st.build(B, 1, 0, n - 1);
        
        ll result = LLONG_MAX;
        for (int i = 0; i <= n - k; ++i) {
            int j = i + k - 1;
            
            // Get the maximum A value in the range [i, j]
            ll max_A = idx[j].first;
            
            // Get the sum of B values in the range [i, j]
            Node res = st.query(1, 0, n - 1, i, j);
            ll sum_B = res.sum;
            
            // Calculate the product
            ll product = max_A * sum_B;
            result = min(result, product);
        }
        
        cout << result << '\n';
    }
    
    return 0;
}