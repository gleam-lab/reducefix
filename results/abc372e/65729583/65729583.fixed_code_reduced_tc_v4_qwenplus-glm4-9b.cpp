// Pseudocode for handling the queries
struct Graph {
    vector<int> parent; // Union-Find parent array
    vector<int> size;   // Union-Find size array
    // Additional data structures for maintaining order of vertices
    // ...

    Graph(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        // Initialize additional data structures
        // ...
    }

    // Find representative of a vertex using path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Union by size
    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v) return false;

        if (size[root_u] > size[root_v]) {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        } else {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        // Update order of vertices in additional data structures
        // ...
        return true;
    }

    // Retrieve k-th largest connected vertex to a given vertex
    int kthLargestConnected(int v, int k) {
        // Use additional data structures to find the k-th largest element
        // ...
    }
};

int main() {
    // Read N and Q
    // Initialize the graph
    Graph graph(N);

    // Process each query
    for (int i = 0; i < Q; ++i) {
        // Read the query
        // Process the query based on its type
        if (queryType == 1) {
            // Add edge and unite vertices
            graph.unite(u, v);
        } else if (queryType == 2) {
            // Find k-th largest connected vertex
            int result = graph.kthLargestConnected(v, k);
            // Print the result
            if (result != -1) {
                cout << result << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}