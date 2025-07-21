#include<bits/stdc++.h>
using namespace std;
vector<int> graph[200005];
int parent[200005];
int size[200005];
vector<int> vertexList[200005];
int findSet(int u) {
    if (parent[u] != u) parent[u] = findSet(parent[u]);
    return parent[u];
}
void unionSets(int u, int v) {
    int rootU = findSet(u);
    int rootV = findSet(v);
    if (rootU != rootV) {
        if (size[rootU] < size[rootV]) swap(rootU, rootV);
        parent[rootV] = rootU;
        size[rootU] += size[rootV];
        vertexList[rootU].insert(vertexList[rootU].end(), vertexList[rootV].begin(), vertexList[rootV].end());
        // Sort the vertices in descending order for faster access
        sort(vertexList[rootU].rbegin(), vertexList[rootU].rend());
    }
}
int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < Q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            unionSets(u, v);
        } else {
            if (findSet(u) != findSet(v)) {
                cout << -1 << endl;
            } else {
                int root = findSet(u);
                if (k > vertexList[root].size()) {
                    cout << -1 << endl;
                } else {
                    cout << vertexList[root][k - 1] << endl;
                }
            }
        }
    }
    return 0;
}