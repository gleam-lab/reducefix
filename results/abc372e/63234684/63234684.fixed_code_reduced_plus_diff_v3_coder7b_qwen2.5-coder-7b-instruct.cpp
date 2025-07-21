#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank, size, *edges;

    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        edges = new vector<int>[n];
        iota(parent.begin(), parent.end(), 0); // Initialize parent array
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        size[y] += size[x]; // Update size of the new set
        edges[y].insert(edges[y].end(), edges[x].begin(), edges[x].end()); // Merge edges
        edges[x].clear(); // Clear old set's edges
        if (rank[x] == rank[y]) ++rank[y]; // Rank update if equal ranks
    }

    int getKthLargest(int x, int k) {
        x = find(x);
        if (k > size[x] || k <= 0) return -1;
        nth_element(edges[x].begin(), edges[x].begin() + k - 1, edges[x].end(), greater<int>());
        return edges[x][k - 1] + 1; // Return k-th largest element
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    while(q--) {
        int type, u, v;
        cin >> type >> u >> v;
        u--; v--; // Adjust for 0-based indexing

        if(type == 1) {
            uf.unite(u, v);
        } else {
            cout << uf.getKthLargest(v, u) << '\n';
        }
    }

    delete[] uf.edges; // Free dynamically allocated memory
    return 0;
}