#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int start, end;
    ll sum;
    Node* left, *right;
    Node(int start, int end) : start(start), end(end), sum(0), left(nullptr), right(nullptr) {}
};

class SegmentTree {
    Node* root;
    void build(Node* node, const vector<pair<int, ll>>& data) {
        if (node->start == node->end) {
            node->sum = data[node->start].second;
            return;
        }
        int mid = (node->start + node->end) / 2;
        node->left = new Node(node->start, mid);
        node->right = new Node(mid + 1, node->end);
        build(node->left, data);
        build(node->right, data);
        node->sum = node->left->sum + node->right->sum;
    }
    
    ll query(Node* node, int L, int R) {
        if (R < node->start || L > node->end) return 0;
        if (L <= node->start && R >= node->end) return node->sum;
        return query(node->left, L, R) + query(node->right, L, R);
    }
    
public:
    SegmentTree(const vector<pair<int, ll>>& data) {
        root = new Node(0, data.size() - 1);
        build(root, data);
    }
    
    ~SegmentTree() {
        deleteTree(root);
    }
    
    ll rangeSum(int L, int R) {
        return query(root, L - 1, R - 1);
    }
    
private:
    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    
    vector<pair<int, ll>> data;
    for (int i = 0; i < n; i++) {
        data.emplace_back(x[i], p[i]);
    }
    
    // Sort data by x values to use as indices in segment tree
    sort(data.begin(), data.end());
    
    int q;
    cin >> q;
    SegmentTree segTree(data);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << segTree.rangeSum(l, r) << endl;
    }
    
    return 0;
}