#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 9;

vector<int> parent(N), size(N, 1);
vector<vector<int>> adj(N);

// Find with path compression
int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

// Union by size
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (size[rootU] < size[rootV]) {
            swap(rootU, rootV);
        }
        parent[rootV] = rootU;
        size[rootU] += size[rootV];
        // Merge the two sets by size
        for (int neighbor : adj[rootV]) {
            adj[rootU].push_back(neighbor);
            parent[neighbor] = rootU;
            size[rootU]++;
        }
        adj[rootV].clear();
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionSets(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int rootV = find(v);
            int subgraphSize = size[rootV];
            if (k > subgraphSize) {
                cout << -1 << endl;
            } else {
                // Find the k-th largest vertex in the subgraph
                vector<int> sortedAdj;
                for (int neighbor : adj[rootV]) {
                    sortedAdj.push_back(neighbor);
                }
                sort(sortedAdj.begin(), sortedAdj.end());
                // Find the k-th largest, which will be the k-th smallest in reverse order
                cout << sortedAdj[subgraphSize - k] << endl;
            }
        }
    }
    return 0;
}