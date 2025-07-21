#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

const int N = 2e5 + 5;

struct Node {
    multiset<int> degree;
    int parent, rank;
};

Node dsu[N];

int find(int u) {
    if (dsu[u].parent != u) {
        dsu[u].parent = find(dsu[u].parent);
    }
    return dsu[u].parent;
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    
    if (u == v) return;
    
    if (dsu[u].rank < dsu[v].rank) swap(u, v);
    
    dsu[v].degree.insert(dsu[u].degree.begin(), dsu[u].degree.end());
    dsu[v].degree.insert(1); // Adding new node with degree 1
    
    dsu[u].degree.clear();
    
    dsu[v].rank += dsu[u].rank + 1;
    dsu[u].parent = v;
}

int kthLargest(vector<int>& degrees, int k) {
    if (k > degrees.size()) return -1;
    auto it = degrees.rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        dsu[i].parent = i;
        dsu[i].rank = 1;
        dsu[i].degree.insert(1);
    }
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        
        if (t == 1) {
            unite(a, b);
        } else {
            a = find(a);
            int k = b - 1;
            cout << kthLargest(dsu[a].degree, k) << '\n';
        }
    }
    
    return 0;
}