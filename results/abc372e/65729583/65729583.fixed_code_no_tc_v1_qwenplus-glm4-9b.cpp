#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int N = 2e5 + 9;

int parent[N];
map<int, set<int>> adj;

void find_set(int v) {
    if (parent[v] != v) {
        parent[v] = find_set(parent[v]);
    }
    return;
}

void union_set(int u, int v) {
    find_set(u);
    find_set(v);
    if (parent[u] != parent[v]) {
        parent[v] = u;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

int kth_largest(int v, int k) {
    find_set(v);
    if (adj[v].size() < k) {
        return -1;
    }
    auto it = --adj[v].upper_bound(-k); // upper_bound returns the iterator past the first element greater than k, so -- gives us the (k-1)th largest
    return -(*it);
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            union_set(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << kth_largest(v, k) << "\n";
        }
    }

    return 0;
}