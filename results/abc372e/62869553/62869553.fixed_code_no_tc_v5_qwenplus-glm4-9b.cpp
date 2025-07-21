#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAX_K = 10;

int parent[MAXN]; // Union-Find parent array
int size[MAXN];   // Union-Find size array
vector<int> adj[MAXN]; // Adjacency list

// Function to find the representative of a node using path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Function to unite two sets
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
}

// Function to add an edge between two nodes
void addEdge(int u, int v) {
    unite(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to process the queries and output the results
void processQueries(int q, vector<pair<string, int>>& queries) {
    for (auto& query : queries) {
        if (query.first == "1") {
            int u = query.second, v = query.second + 1;
            addEdge(u, v);
        } else {
            int v = query.second, k = query.second + 1;
            int root = find(v);
            if (adj[root].size() < k) {
                cout << "-1" << endl;
            } else {
                // Since k is at most 10, we can store the first 10 largest nodes
                // We sort the adjacency list and print the k-th largest node
                sort(adj[root].begin(), adj[root].end());
                cout << adj[root][adj[root].size() - k] << endl;
            }
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<string, int>> queries;

    // Read all queries
    for (int i = 0; i < q; ++i) {
        int op, x, y;
        cin >> op >> x >> y;
        queries.push_back({to_string(op), x});
    }

    // Initialize Union-Find
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }

    // Process the queries
    processQueries(q, queries);

    return 0;
}