#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN];
int size[MAXN];
int vertexCount[MAXN];

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        vertexCount[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionVertices(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU != rootV) {
        if (size[rootU] < size[rootV]) {
            swap(rootU, rootV);
        }
        parent[rootV] = rootU;
        size[rootU] += size[rootV];
        vertexCount[rootU] += vertexCount[rootV];
        vertexCount[rootV] = 0;
    }
}

int processQuery1(int u, int v) {
    unionVertices(u, v);
    return find(v);
}

int processQuery2(int v, int k) {
    int rootV = find(v);
    if (vertexCount[rootV] < k) {
        return -1;
    }
    return vertexCount[rootV] - k + 1;
}

int main() {
    int n, q;
    cin >> n >> q;

    initialize(n);

    int op, u, v, result;
    while (q--) {
        cin >> op >> u >> v;
        if (op == 1) {
            cout << processQuery1(u, v) << endl;
        } else {
            cout << processQuery2(v, k) << endl;
        }
    }

    return 0;
}