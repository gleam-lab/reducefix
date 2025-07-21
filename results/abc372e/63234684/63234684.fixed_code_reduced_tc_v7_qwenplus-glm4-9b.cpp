#include <iostream>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool union_set(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] > size[y]) {
                parent[y] = x;
                size[x] += size[y];
            } else {
                parent[x] = y;
                size[y] += size[x];
            }
            return true;
        }
        return false;
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
            uf.union_set(a, b);
        } else {
            int root = uf.find(b);
            if (uf.size[root] < b) {
                cout << -1 << endl;
            } else {
                for (int i = uf.size[root] - 1; i >= 0; i--) {
                    int node = uf.find(uf.parent[root] + i);
                    if (node == root) {
                        cout << uf.parent[root] + i + 1 << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}