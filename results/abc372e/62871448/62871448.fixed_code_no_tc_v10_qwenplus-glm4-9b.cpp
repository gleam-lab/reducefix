#include<bits/stdc++.h>
using namespace std;
vector<int> graph[200005];
int size[200005];
int parent[200005];
int find(int node) {
    if (parent[node] == node) return node;
    parent[node] = find(parent[node]);
    return parent[node];
}
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (size[rootU] < size[rootV]) swap(rootU, rootV);
        parent[rootV] = rootU;
        size[rootU] += size[rootV];
    }
}
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unionSets(u, v);
        } else if (op == 2) {
            int rootV = find(v);
            sort(graph[rootV].begin(), graph[rootV].end(), greater<int>());
            if (k < graph[rootV].size()) {
                cout << graph[rootV][k - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}