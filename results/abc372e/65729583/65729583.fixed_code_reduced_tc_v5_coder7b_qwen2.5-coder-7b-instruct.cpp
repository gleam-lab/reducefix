#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <functional>

using namespace std;

typedef long long int ll;

struct UF {
    vector<int> parent, rank;

    UF(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[px] = py;
            if (rank[px] == rank[py]) {
                rank[py]++;
            }
        }
    }
};

struct Node {
    set<int> neighbors;

    void insert(int neighbor) {
        neighbors.insert(neighbor);
    }

    void erase(int neighbor) {
        neighbors.erase(neighbor);
    }

    int getKthLargest(int k) {
        auto it = neighbors.rbegin();
        advance(it, k - 1);
        return *it;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UF uf(n + 1);
    unordered_map<int, Node> nodes;
    
    for (int i = 1; i <= n; ++i) {
        nodes[i] = Node();
    }

    for (int i = 0; i < q; ++i) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            uf.unite(u, v);
            u = uf.find(u);
            nodes[u].insert(v);
            nodes[u].insert(u);
            nodes[v].insert(u);
            nodes[v].insert(v);
        } else {
            cin >> u >> k;
            u = uf.find(u);
            if (nodes[u].neighbors.size() < k) {
                cout << -1 << endl;
            } else {
                cout << nodes[u].getKthLargest(k) << endl;
            }
        }
    }

    return 0;
}