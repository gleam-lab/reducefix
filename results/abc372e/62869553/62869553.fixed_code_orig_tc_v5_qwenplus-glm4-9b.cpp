#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> graph;
vector<int> parent;
vector<int> rank;

int find_set(int v) {
    if (v == parent[v]) return v;
    parent[v] = find_set(parent[v]); // path compression
    return parent[v];
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    parent.resize(N + 1);
    rank.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    graph.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        graph[i].push_back(i);
    }

    for (int i = 0; i < Q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;

        if (op == 1) {
            // Add edge
            union_sets(u, v);
        } else if (op == 2) {
            // Find k-th largest neighbor
            set<int> neighbors;
            for (int neighbor : graph[v]) {
                if (find_set(neighbor) == find_set(v)) {
                    neighbors.insert(neighbor);
                }
            }
            if (k > neighbors.size()) {
                cout << "-1\n";
            } else {
                cout << *next_permutation(neighbors.begin(), neighbors.end()) << "\n";
            }
        }
    }

    return 0;
}