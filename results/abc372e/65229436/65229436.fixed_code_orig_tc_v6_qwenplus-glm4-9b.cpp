#include <iostream>
#include <vector>
#include <set>
using namespace std;

using ll = long long;
using pi = pair<int, int>;

const int INF = 1e9;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
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
    vector<set<int>> components(n);

    for (int i = 0; i < n; ++i) {
        components[i].insert(i);
    }

    vector<int> results;

    for (int qi = 0; qi < q; ++qi) {
        int command, u, v, v_root, k;
        cin >> command;

        if (command == 1) {
            cin >> u >> v;
            --u; --v;
            v_root = uf.findRoot(v);
            uf.unite(u, v);
            if (components[v].size() < components[v_root].size()) {
                components[v_root].splice(components[v_root].end(), components[v]);
            } else {
                components[v_root].splice(components[v_root].end(), components[v]);
            }
            components[v].clear();
        } else if (command == 2) {
            cin >> v >> k;
            --v;
            v_root = uf.findRoot(v);
            if (components[v_root].size() < k) {
                results.push_back(-1);
            } else {
                auto it = components[v_root].rbegin();
                advance(it, k - 1);
                results.push_back(*it + 1);
            }
        }
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}