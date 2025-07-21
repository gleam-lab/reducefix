#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200005;
vector<int> parents(N + 1); // Union-Find parent pointers

// Find the root of the vertex using path compression
int find(int vertex) {
    if (parents[vertex] != vertex) {
        parents[vertex] = find(parents[vertex]); // Path compression
    }
    return parents[vertex];
}

// Union the two sets containing vertices u and v
void union_sets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        parents[root_u] = root_v; // Union by rank can be used here for optimization
    }
}

// Main function to handle queries
int main() {
    int n, q;
    cin >> n >> q;

    // Initialize union-find structure
    for (int i = 1; i <= n; ++i) {
        parents[i] = i;
    }

    // Process queries
    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if (type == 1) {
            // Add edge by uniting sets
            union_sets(u, v);
        } else {
            // For query type 2, find the root of v
            int root_v = find(v);
            // Output the k-th largest connected vertex
            int count = 0;
            for (int i = n; i > 0; --i) {
                if (find(i) == root_v) {
                    count++;
                    if (count == v) {
                        cout << i << '\n';
                        break;
                    }
                }
            }
            if (count < v) {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}