#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int v, int u) {
    auto it = find(pq[v].begin(), pq[v].end(), u);
    if (it != pq[v].end()) pq[v].erase(it);
    pq[v].push_back(u);
    while (pq[v].size() > 10) pq[v].pop();
}

void dfs(int node, int parent) {
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
        updatePQ(node, neighbor);
    }
}

void preprocess() {
    for (int i = 1; i <= n; ++i) {
        dfs(i, -1);
    }
}

int getKthLargest(int v, int k) {
    if (pq[v].size() < k) return -1;
    auto it = pq[v].begin();
    advance(it, k - 1);
    return *it;
}

int main() {
    cin >> n >> q;
    preprocess();
    for (int i = 0; i < q; ++i) {
        int op, v, k;
        cin >> op >> v >> k;
        if (op == 1) {
            // No need to do anything for type 1 queries
        } else {
            cout << getKthLargest(v, k) << "\n";
        }
    }
    return 0;
}