#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;

    UnionFind(int n) : par(n), rank(n, 1), size(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int root(int v) {
        if (v == par[v]) return v;
        par[v] = root(par[v]);
        return par[v];
    }

    bool issame(int v, int u) {
        return root(v) == root(u);
    }

    void merge(int v, int u) {
        int vRoot = root(v);
        int uRoot = root(u);

        if (vRoot == uRoot) return;

        if (rank[vRoot] < rank[uRoot]) {
            swap(vRoot, uRoot);
        }

        if (rank[vRoot] == rank[uRoot]) rank[vRoot]++;

        par[uRoot] = vRoot;
        size[vRoot] += size[uRoot];
    }

    int getSize(int v) {
        return size[root(v)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    vector<int> edges(n + 1);
    vector<int> answers;

    for (int i = 1; i <= q; i++) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if (type == 1) {
            uf.merge(u - 1, v - 1);
        } else {
            if (uf.getSize(u - 1) <= v) {
                answers.push_back(-1);
            } else {
                int rootU = uf.root(u - 1);
                sort(edges[rootU].begin(), edges[rootU].end());
                answers.push_back(edges[rootU][v - 2]); // adjust indexing
            }
        }
    }

    for (int answer : answers) {
        cout << answer << "\n";
    }

    return 0;
}