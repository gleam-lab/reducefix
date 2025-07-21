#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
const int N = 2e5 + 5;

vector<int> parent(N);

// Find the root of the node x
int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]); // Path compression
    return parent[x];
}

// Union of two sets by size
void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        // Union by size
        if (parent[x].size() < parent[y].size()) swap(x, y);
        parent[x].insert(parent[x].end(), parent[y].begin(), parent[y].end());
        parent[x].resize(parent[x].size() - 1); // Remove duplicate
        parent[y] = parent[x];
    }
}

// Query the k-th largest vertex in the set of vertices connected to vertex v
int query(int v, int k) {
    int root = find(v);
    if (k > parent[root].size()) return -1; // More queries than elements in the set
    return parent[root][parent[root].size() - k]; // Get the k-th largest element
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Initialize parent pointers
    for (int i = 1; i <= n; ++i) {
        parent[i].push_back(i);
        parent[i].resize(100); // Limit the size of the set to maintain efficiency
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            union_sets(a, b);
        } else if (t == 2) {
            cout << query(b, b - k) << '\n'; // Output the k-th largest vertex
        }
    }

    return 0;
}