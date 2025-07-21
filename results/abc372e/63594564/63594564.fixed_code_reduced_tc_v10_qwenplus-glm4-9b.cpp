#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_K = 10;

vector<int> parent(MAX_N + 1);
vector<vector<int>> adj(MAX_N + 1);
vector<vector<int>> subtree(MAX_N + 1);

void findSubtree(int v, int p) {
    subtree[v][0] = 1; // count this node
    for (int u : adj[v]) {
        if (u == p) continue;
        findSubtree(u, v);
        subtree[v][0] += subtree[u][0];
        sort(subtree[u].begin(), subtree[u].end());
    }
    sort(subtree[v].begin(), subtree[v].end(), greater<int>());
}

int kthLargest(int v, int k) {
    if (parent[v] == v) return -1; // if v is a root, no parent, hence no subtree
    if (subtree[parent[v]][k - 1] != -1) return subtree[parent[v]][k - 1];
    return -1;
}

int findParent(int v) {
    if (parent[v] == v) return v;
    parent[v] = findParent(parent[v]);
    return parent[v];
}

void unionNodes(int u, int v) {
    int rootU = findParent(u);
    int rootV = findParent(v);
    if (rootU != rootV) {
        findSubtree(rootV, rootU);
        parent[rootU] = rootV;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionNodes(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << kthLargest(v, k) << '\n';
        }
    }
    
    return 0;
}