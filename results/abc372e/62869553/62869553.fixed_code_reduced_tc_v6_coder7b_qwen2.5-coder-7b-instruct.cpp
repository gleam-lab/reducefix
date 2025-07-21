#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct BIT {
    vector<int> tree;
    BIT(int size) : tree(size + 1) {}

    void update(int idx, int val) {
        while (idx <= tree.size()) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

vector<vector<int>> adj(MAXN);
BIT bit(MAXN);

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    bit.update(deg[u], -1);
    bit.update(deg[v], -1);
    deg[u]++;
    deg[v]++;
    bit.update(deg[u], 1);
    bit.update(deg[v], 1);
}

int getKthLargest(int v, int k) {
    if (deg[v] < k) return -1;
    return k + bit.query(k) - 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> deg(n + 1, 0);
    
    for (int i = 0; i < q; i++) {
        int type, u, v, k;
        cin >> type;
        
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else {
            cin >> u >> k;
            cout << getKthLargest(u, k) << "\n";
        }
    }
    
    return 0;
}