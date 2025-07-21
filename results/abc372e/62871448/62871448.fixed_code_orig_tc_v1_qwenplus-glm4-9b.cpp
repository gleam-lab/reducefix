#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
vector<int> graph[MAX];
int parent[MAX];
int size[MAX];
int rank[MAX];
int kth_largest[MAX][10]; // Use a fixed size array of 10 to store k-th largest vertices

int find_set(int u) {
    if (parent[u] != u) {
        parent[u] = find_set(parent[u]); // Path compression
    }
    return parent[u];
}

void union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        // Union by rank
        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
            size[root_u] += size[root_v];
        }

        // Add k-th largest vertices from both sets into one set
        for (int k = 0; k < 10; ++k) {
            if (kth_largest[root_v][k] != -1) {
                kth_largest[root_u][k] = kth_largest[root_v][k];
            }
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        for (int k = 0; k < 10; ++k) {
            kth_largest[i][k] = -1;
        }
    }

    while (q--) {
        int type, u, v, k;
        cin >> type;

        if (type == 1) {
            cin >> u >> v;
            union_sets(u, v);
        } else {
            cin >> v >> k;
            int root_v = find_set(v);
            if (k > size[root_v]) {
                cout << -1 << endl;
            } else {
                cout << kth_largest[root_v][k-1] << endl;
            }
        }
    }

    return 0;
}