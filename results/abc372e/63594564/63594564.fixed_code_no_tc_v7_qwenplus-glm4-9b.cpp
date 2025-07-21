#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <vector <int>> adj; // adjacency list for the graph
vector <int> size; // size of each component
vector <int> rank; // rank of each component in the union-find structure
vector <int> comp; // component of each vertex

int n, q;
int nextComp = 1; // next available component ID

void init() {
    adj.resize(n + 1);
    size.resize(nextComp + 1, 1);
    rank.resize(nextComp + 1, 0);
    comp.resize(n + 1, 0);
}

int find(int u) {
    if (u == comp[u]) return u;
    int p = find(comp[u]);
    comp[u] = p; // path compression
    return p;
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        // union by rank
        if (rank[rootU] > rank[rootV]) {
            comp[rootV] = rootU;
            size[rootU] += size[rootV];
        } else if (rank[rootU] < rank[rootV]) {
            comp[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            comp[rootU] = rootV;
            size[rootV] += size[rootU];
            rank[rootV]++;
        }
    }
}

int getSize(int v) {
    int root = find(v);
    return size[root];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    init();
    for (int i = 1; i <= n; ++i) {
        comp[i] = i; // initialize each vertex to its own component
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 1) { // add edge
            adj[u].push_back(v);
            adj[v].push_back(u);
            unite(u, v);
        } else if (t == 2) { // find k-th largest component vertex
            if (find(u) != find(v)) {
                cout << "-1\n"; // u and v are not in the same component
            } else {
                vector<int> verticesInComp;
                int root = find(u);
                for (int i = 1; i <= n; ++i) {
                    if (find(i) == root) {
                        verticesInComp.push_back(i);
                    }
                }
                if (verticesInComp.size() < v) {
                    cout << "-1\n";
                } else {
                    cout << verticesInComp[verticesInComp.size() - v] << '\n';
                }
            }
        }
    }

    return 0;
}