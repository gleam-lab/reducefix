#include "bits/stdc++.h"

using namespace std;

#define ll long long

int const N = 2e5 + 5;

vector<int> parent(N+1); // parent[i] points to the parent of i, or to itself if i is a root
vector<vector<pair<int, int>>> adj(N+1); // adj[i] stores pairs (neighbor, edge_weight)

// Find with path compression
int find(int v) {
    if (parent[v] != v) {
        parent[v] = find(parent[v]);
    }
    return parent[v];
}

// Union by rank, though not strictly necessary here
void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        parent[root_u] = root_v;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) { // Add edge
            unionSets(u, v);
            adj[u].push_back({v, 1}); // Assuming all edges have the same weight
            adj[v].push_back({u, 1});
        } else if (t == 2) { // Query k-th largest connected vertex
            cout << find(u);
            int root_v = find(v);
            int count = 0;
            for (int neighbor : adj[root_v]) {
                if (find(u) == find(neighbor.first)) {
                    count++;
                    if (count == v) {
                        cout << " " << neighbor.first;
                        break;
                    }
                }
            }
            if (count < v) {
                cout << " -1";
            }
            cout << '\n';
        }
    }

    return 0;
}