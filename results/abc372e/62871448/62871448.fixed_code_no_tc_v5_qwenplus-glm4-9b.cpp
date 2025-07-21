#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
const int MAX_L = 11; // To store at least 2^10 - 1 elements

vector<int> adj[MAX_N];
int parent[MAX_N];

int findSet(int u) {
    if (u == parent[u]) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u != v) {
        parent[v] = u;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Initialize parent array to represent each node's root
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        
        if (type == 1) {
            // Add edge
            if (findSet(u) != findSet(v)) {
                unionSets(u, v);
            }
        } else if (type == 2) {
            // Query k-th largest vertex
            int rootV = findSet(v);
            int count = 0;
            int kthLargest = -1;
            for (int neighbor : adj[rootV]) {
                if (findSet(neighbor) == rootV) {
                    count++;
                    if (count == k) {
                        kthLargest = max(kthLargest, neighbor);
                    }
                    if (count > k) break;
                }
            }
            if (count >= k) {
                cout << kthLargest << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}