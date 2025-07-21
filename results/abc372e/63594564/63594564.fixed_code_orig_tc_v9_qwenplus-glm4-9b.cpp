#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;

vector<int> parent(MAX_N + 1);
vector<vector<int>> adj(MAX_N + 1);
vector<int> size(MAX_N + 1);

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Initialize union-find structure
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    // Process queries
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        
        if (t == 1) {
            // Union operation
            unite(a, b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        } else {
            // Find the root of b
            int rootB = find(b);
            // Sort the adjacency list of the root
            sort(adj[rootB].rbegin(), adj[rootB].rend());
            // Output the k-th largest vertex
            if (k <= size[rootB]) {
                cout << adj[rootB][k - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    
    return 0;
}