#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;

struct UnionFind {
    vector<int> parents;
    vector<vector<int>> components;

    UnionFind(int size) {
        parents.resize(size + 1, -1);
        components.resize(size + 1);
    }

    int root(int x) {
        if (parents[x] < 0) return x;
        return parents[x] = root(parents[x]);
    }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (parents[x] > parents[y]) swap(x, y);
            parents[x] += parents[y];
            parents[y] = x;
        }
    }

    void addEdge(int x, int y) {
        merge(x, y);
    }

    int find(int x) {
        return root(x);
    }

    int size(int x) {
        return -parents[root(x)];
    }

    vector<int> getComponent(int x) {
        x = root(x);
        return components[x];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    while (q--) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--; b--;

        if (ty == 1) {
            uf.addEdge(a, b);
        } else {
            int v = uf.root(a);
            vector<int> comp = uf.getComponent(v);
            if (comp.size() < b) {
                cout << -1 << endl;
            } else {
                cout << comp[b - 1] + 1 << endl;
            }
        }
    }

    return 0;
}