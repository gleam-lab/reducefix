#include<bits/stdc++.h>
using namespace std;
int parent[200005];
int size[200005];
vector<int> adj[200005];
vector<int> tree[200005]; // To store the vertices in the connected component

int find(int v) {
    if (parent[v] == v) return v;
    parent[v] = find(parent[v]); // Path compression
    return parent[v];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
        vector<int> uComponent = adj[u];
        vector<int> vComponent = adj[v];
       åå¹¶ä¸¤ä¸ªè¿éåéï¼ä¿çè¾å¤§çä¸é¨å
        sort(uComponent.begin(), uComponent.end(), greater<int>());
        sort(vComponent.begin(), vComponent.end(), greater<int>());
        int i = 0, j = 0;
        while (i < uComponent.size() && j < vComponent.size()) {
            if (uComponent[i] < vComponent[j]) {
                tree[u].push_back(uComponent[i]);
                i++;
            } else {
                tree[u].push_back(vComponent[j]);
                j++;
            }
        }
        while (i < uComponent.size()) {
            tree[u].push_back(uComponent[i]);
            i++;
        }
        while (j < vComponent.size()) {
            tree[u].push_back(vComponent[j]);
            j++;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    int op, u, v, k;
    for (int i = 0; i < q; i++) {
        cin >> op >> u >> v;
        if (op == 1) {
            unionSets(u, v);
        } else if (op == 2) {
            int root = find(v);
            if (tree[root].size() < k) {
                cout << -1 << endl;
            } else {
                cout << tree[root][k - 1] << endl; // k-1 because we need the k-th largest
            }
        }
    }
    return 0;
}