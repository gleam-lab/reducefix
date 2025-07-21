#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN);
vector<int> rank(MAXN);

int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);  // Path compression
    return parent[x];
}

int unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    return rootX;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<vector<pair<int, int>>> adj[MAXN];  // Adjacency list with edge weights
    for (int i = 0; i < Q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            // Add edge
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 0});
            unionSets(u, v);
        } else if (op == 2) {
            // Find k-th largest
            int root = find(v);
            sort(adj[root].begin(), adj[root].end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first > b.first;
            });
            int count = 0;
            for (auto &edge : adj[root]) {
                if (edge.first == v) continue;  // Skip the vertex itself
                count++;
                if (count == k) {
                    cout << edge.first << endl;
                    break;
                }
            }
            if (count < k) cout << -1 << endl;
        }
    }

    return 0;
}