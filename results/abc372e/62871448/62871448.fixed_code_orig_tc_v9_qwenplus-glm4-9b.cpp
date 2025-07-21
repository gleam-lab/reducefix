#include<bits/stdc++.h>
using namespace std;
int parent[200005]; // Union-Find structure to keep track of connected components

// Find function with path compression
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int n, q;

int main() {
    cin >> n >> q;
    // Initialize union-find structure
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    int op, u, v, k;
    vector<pair<int, int>> queries; // To store the indices of queries for sorting
    vector<int> results; // To store the results of type 2 queries
    
    // Read all queries
    while (q--) {
        cin >> op >> u >> v;
        if (op == 1) {
            // Union operation
            int root_u = find(u);
            int root_v = find(v);
            if (root_u != root_v) {
                parent[root_v] = root_u;
            }
        } else {
            // Find the k-th largest vertex in the connected component of v
            int root_v = find(v);
            vector<int> connected; // To store the vertices connected to v
            for (int i = 1; i <= n; i++) {
                if (find(i) == root_v) {
                    connected.push_back(i);
                }
            }
            sort(connected.rbegin(), connected.rend()); // Sort in descending order
            if (k <= connected.size()) {
                results.push_back(connected[k - 1]);
            } else {
                results.push_back(-1);
            }
        }
    }
    
    // Output the results of type 2 queries
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}