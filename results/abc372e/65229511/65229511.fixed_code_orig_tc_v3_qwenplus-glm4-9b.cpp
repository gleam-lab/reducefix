#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = 200100;

int parent[MAX_N];
set<int> components[MAX_N];
vector<set<int>> adj[MAX_N];

int find_set(int v) {
    if (parent[v] == v) return v;
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        if (components[root_u].size() < components[root_v].size()) {
            swap(root_u, root_v);
        }
        for (int node : components[root_v]) {
            parent[node] = root_u;
            adj[root_u].insert(adj[node].begin(), adj[node].end());
            adj[node].clear();
        }
        components[root_u].insert(components[root_v].begin(), components[root_v].end());
        components[root_v].clear();
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            union_sets(u - 1, v - 1);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            int root_v = find_set(v - 1);
            if (components[root_v].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = components[root_v].rbegin();
                advance(it, k - 1);
                cout << *it + 1 << endl;
            }
        }
    }

    return 0;
}