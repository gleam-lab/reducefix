#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
vector<int> parent(N + 1);
vector<vector<int>> adj(N + 1);
vector<vector<int>> graph(N + 1);

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    int ul = find(u), vl = find(v);
    if (ul == vl) return;
    if (adj[ul].size() < adj[vl].size()) swap(ul, vl);
    for (int v : adj[vl]) parent[v] = ul;
    adj[ul].insert(adj[ul].end(), adj[vl].begin(), adj[vl].end());
    sort(adj[ul].begin(), adj[ul].end());
    adj[vl].clear();
}

void addEdge(int u, int v) {
    if (find(u) != find(v)) unionSets(u, v);
}

int kthLargest(int vertex, int k) {
    int leader = find(vertex);
    if (k > adj[leader].size()) return -1;
    return adj[leader][adj[leader].size() - k];
}

int main() {
    int n, q;
    cin >> n >> q;
    fill_n(parent.begin(), n + 1, -1);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            addEdge(u, v);
        } else {
            cout << kthLargest(u, v) << '\n';
        }
    }
    return 0;
}