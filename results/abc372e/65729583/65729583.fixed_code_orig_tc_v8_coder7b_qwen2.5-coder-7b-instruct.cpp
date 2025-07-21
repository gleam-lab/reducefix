#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

class UnionFind {
public:
    unordered_map<int, int> parent;
    unordered_map<int, multiset<int>> rank;

    UnionFind(int n) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            rank[i].insert(-i);
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (rank[x].size() < rank[y].size())
            swap(x, y);
        rank[x].insert(rank[y].begin(), rank[y].end());
        rank.erase(y);
        parent[y] = x;
    }

    int kth_largest(int x, int k) {
        x = find(x);
        auto it = rank[x].upper_bound(-k);
        if (it == rank[x].end())
            return -1;
        return -(*it);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            uf.unite(u, v);
        } else {
            cin >> u >> k;
            cout << uf.kth_largest(u, k) << '\n';
        }
    }

    return 0;
}