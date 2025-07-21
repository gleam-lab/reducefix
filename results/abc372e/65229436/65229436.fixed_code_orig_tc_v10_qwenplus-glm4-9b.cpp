#include <iostream>
#include <vector>
#include <set>
using namespace std;

class UnionFind {
private:
    vector<int> parent, size;

public:
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;

        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        return true;
    }

    int getSize(int x) {
        return size[findRoot(x)];
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<set<int>> components(N);
    for (int i = 0; i < N; ++i) {
        components[i].insert(i);
    }

    for (int i = 0; i < Q; ++i) {
        int type, v, k;
        cin >> type;
        if (type == 1) {
            cin >> v >> k;
            --v; --k; // Convert to 0-based index
            int rootV = uf.findRoot(v);
            int rootK = uf.findRoot(k);
            if (rootV != rootK) {
                uf.unite(rootV, rootK);
            }
        } else if (type == 2) {
            cin >> v >> k;
            --v; --k; // Convert to 0-based index
            int root = uf.findRoot(v);
            if (components[root].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = components[root].upper_bound(k - 1);
                if (it == components[root].begin()) {
                    cout << -1 << endl;
                } else {
                    --it;
                    cout << *it + 1 << endl; // Convert back to 1-based index
                }
            }
        }
    }

    return 0;
}