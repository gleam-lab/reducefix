#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

struct DSU {
    int parent[MAXN];
    multiset<int> elements[MAXN];

    DSU() {
        for (int i = 0; i < MAXN; i++) {
            parent[i] = i;
            elements[i].insert(-i); // Store negatives to simulate max-heap
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (elements[u].size() < elements[v].size()) {
            swap(u, v);
        }

        for (auto it = elements[v].begin(); it != elements[v].end(); ++it) {
            elements[u].insert(*it);
            if (elements[u].size() > 10) {
                elements[u].erase(elements[u].begin());
            }
        }
        elements[v].clear();
        parent[v] = u;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    DSU dsu;
    int N, Q;
    cin >> N >> Q;

    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            dsu.merge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = dsu.find(v);
            if (dsu.elements[root].size() < k) {
                cout << "-1\n";
            } else {
                auto it = dsu.elements[root].rbegin();
                advance(it, k-1);
                cout << -(*it) << '\n';
            }
        }
    }

    return 0;
}