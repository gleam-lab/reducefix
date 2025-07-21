#include<bits/stdc++.h>
using namespace std;
int parent[200005]; // Union-find parent array
int size[200005];   // Union-find size array
vector<int> adj[200005]; // Adjacency list for each vertex

// Find the root of the set with path compression
int findRoot(int x) {
    if (parent[x] != x) {
        parent[x] = findRoot(parent[x]);
    }
    return parent[x];
}

// Union two sets with union by size
void unionSets(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);

    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
}

// Process each query
void processQueries(int n, int q) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;

        if (op == 1) {
            // Add edge (u, v)
            unionSets(u, v);
        } else if (op == 2) {
            // Find k-th largest vertex connected to v
            int vRoot = findRoot(v);
            int count = 0;
            for (int neighbor : adj[vRoot]) {
                if (findRoot(neighbor) == vRoot) {
                    adj[vRoot].push_back(neighbor);
                    count++;
                    if (count == k) {
                        cout << neighbor << '\n';
                        break;
                    }
                }
            }
            if (count < k) {
                cout << "-1\n";
            }
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    processQueries(n, q);
    return 0;
}