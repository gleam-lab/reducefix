#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200005
vector<int> edges[MAXN]; // Adjacency list for the graph
vector<int> sz(MAXN);      // Size of the component
int parent[MAXN];          // Parent of each node

// Find function with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union function with sizes of components
void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (sz[rootX] < sz[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        sz[rootX] += sz[rootY];
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        if (query == 1) {
            int u, v;
            cin >> u >> v;
            if (find(u) != find(v)) {
                union_set(u, v);
            }
        } else if (query == 2) {
            int v, k;
            cin >> v >> k;
            int rootV = find(v);
            int count = 0;
            vector<int> nodes;
            for (int neighbor : edges[rootV]) {
                if (find(neighbor) == rootV) {
                    nodes.push_back(neighbor);
                    count++;
                    if (count == k) {
                        cout << neighbor << '\n';
                        break;
                    }
                }
            }
            if (count < k) {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}