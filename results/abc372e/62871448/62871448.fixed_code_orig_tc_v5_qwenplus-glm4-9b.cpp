#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int parent[MAXN];
int size[MAXN];

int find(int x) {
    if (x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

void unionVertices(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        // Union by size
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
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
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionVertices(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int rootV = find(v);
            sort(size + 1, size + 1 + size[rootV]); // Sort the sizes of the component
            if (k <= size[rootV]) {
                cout << size[rootV + size[rootV] - k] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}