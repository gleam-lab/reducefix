#include<bits/stdc++.h>
using namespace std;
int parent[200005]; // Parent array for union-find

// Find function with path compression
int find(int v) {
    if (parent[v] != v) {
        parent[v] = find(parent[v]); // Path compression
    }
    return parent[v];
}

// Union function to merge two sets
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        parent[rootV] = rootU; // Union the sets
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Initialize union-find structure
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    int u, v;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        if (u == 1) {
            // Union operation
            unionSets(u, v);
        } else {
            // Find the root of the connected component of v
            int rootV = find(v);
            // Vector to store the vertices in the connected component
            vector<int> components;
            for (int j = 1; j <= n; j++) {
                if (find(j) == rootV) {
                    components.push_back(j);
                }
            }
            // Sort the components in descending order
            sort(components.begin(), components.end(), greater<int>());
            
            // Output the k-th largest component if it exists
            if (k > 0 && k <= components.size()) {
                cout << components[k-1] << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }
    
    return 0;
}