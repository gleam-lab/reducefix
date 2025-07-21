#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXK = 10;

int parent[MAXN];
vector<int> adj[MAXN];
vector<int> tree[MAXN][MAXK + 1]; // k-th level adjacency list
int rank[MAXN];

void findSet(int x) {
    if (x == parent[x]) return;
    parent[x] = findSet(parent[x]);
}

void unionSet(int x, int y) {
    if (rank[x] < rank[y]) {
        parent[x] = y;
    } else if (rank[x] > rank[y]) {
        parent[y] = x;
    } else {
        parent[y] = x;
        rank[x]++;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Initialize parent array for union-find
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    int u, v, k;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        if (u == 1) { // Add edge
            findSet(u);
            findSet(v);
            if (parent[u] != parent[v]) {
                unionSet(u, v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        } else if (u == 2) { // Query k-th largest adjacent vertex
            findSet(v);
            k = parent[v];
            vector<int> &nodes = tree[v][k];
            if (nodes.size() < k) {
                cout << -1 << '\n';
            } else {
                cout << nodes[nodes.size() - k] << '\n';
            }
        }
    }
    
    return 0;
}