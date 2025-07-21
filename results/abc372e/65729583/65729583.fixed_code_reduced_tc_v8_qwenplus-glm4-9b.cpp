#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 9;

int parent[N];
vector<int> components[1 << 17]; // Large enough to hold all connected components

void find_parent(int v) {
    if (parent[v] != v)
        parent[v] = find_parent(parent[v]);
}

void union_sets(int u, int v) {
    find_parent(u);
    find_parent(v);
    if (parent[u] != parent[v]) {
        if (components[parent[v]].size() < components[parent[u]].size()) {
            swap(parent[u], parent[v]);
            swap(components[parent[u]], components[parent[v]]);
        }
        components[parent[u]].insert(v);
        parent[v] = parent[u];
    }
}

int find_kth_largest(int v, int k) {
    find_parent(v);
    int size = components[parent[v]].size();
    if (k > size)
        return -1; // k-th element doesn't exist if k > size
    return *upper_bound(components[parent[v]].rbegin(), components[parent[v]].rend(), -k); // Upper bound in reverse order
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            queries.push_back({u, v});
        } else {
            int v, k;
            cin >> v >> k;
            queries.push_back({v, k});
        }
    }

    // Initialize parent array
    for (int i = 0; i <= n; ++i)
        parent[i] = i;

    // Process queries
    for (auto& q : queries) {
        if (q.first == 1) {
            int u = q.second.first;
            int v = q.second.second;
            union_sets(u, v);
        } else {
            int v = q.second.first;
            int k = q.second.second;
            cout << find_kth_largest(v, k) << endl;
        }
    }

    return 0;
}