#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent, vector<int>& dist) {
    for (int child : adj[node]) {
        if (child != parent) {
            dist[child] = dist[node] + 1;
            dfs(child, node, dist);
        }
    }
}

int findKthLargest(int v, int k) {
    vector<int> dist(adj[v].size());
    iota(dist.begin(), dist.end(), 0); // Initialize distances with indices
    sort(dist.begin(), dist.end(), [&](int i, int j){ return adj[v][i] > adj[v][j]; });
    if (k <= adj[v].size()) {
        return adj[v][dist[k - 1]];
    } else {
        return -1;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            cout << findKthLargest(v, k) << "\n";
        }
    }
    return 0;
}