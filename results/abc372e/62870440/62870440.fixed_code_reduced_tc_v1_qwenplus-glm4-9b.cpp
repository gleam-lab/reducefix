#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int> parent;
vector<int> rank;
vector<set<int>> components;

int find_set(int v) {
    if (parent[v] != v) {
        parent[v] = find_set(parent[v]); // Path compression
    }
    return parent[v];
}

void union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        // Union by rank
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
            components[root_u].insert(v);
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
            components[root_v].insert(u);
        } else {
            parent[root_v] = root_u;
            components[root_u].insert(v);
            rank[root_u]++;
        }
    }
}

int main() {
    cin >> n >> q;
    parent.resize(n + 1);
    rank.resize(n + 1);
    components.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
        components[i].insert(i);
    }

    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else if (op == 2) {
            int root_v = find_set(v);
            if (k > components[root_v].size()) {
                cout << -1 << "\n";
            } else {
                cout << *components[root_v].rbegin() << "\n"; // Get the k-th largest element
            }
        }
    }

    return 0;
}