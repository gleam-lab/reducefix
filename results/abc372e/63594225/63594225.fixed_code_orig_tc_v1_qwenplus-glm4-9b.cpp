#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 200005

vector<int> parent(MAX_N + 1);
vector<vector<int>> adj(MAX_N + 1);
vector<vector<int>> mergedAdj;

int find(int u) {
    if (parent[u] == u) return u;
    parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    parent[v] = u;

    // Merge adjacency lists
    mergedAdj[u].insert(mergedAdj[u].end(), mergedAdj[v].begin(), mergedAdj[v].end());
    sort(mergedAdj[u].rbegin(), mergedAdj[u].rend());

    // Remove duplicates
    mergedAdj[u].erase(unique(mergedAdj[u].begin(), mergedAdj[u].end()), mergedAdj[u].end());
}

int solveQuery2(int v, int k) {
    int root = find(v);
    if (k > mergedAdj[root].size()) return -1;
    return mergedAdj[root][k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        mergedAdj.push_back({i});
    }

    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            unionSets(u, v);
        } else if (type == 2) {
            cout << solveQuery2(v, v) << '\n';
        }
    }

    return 0;
}