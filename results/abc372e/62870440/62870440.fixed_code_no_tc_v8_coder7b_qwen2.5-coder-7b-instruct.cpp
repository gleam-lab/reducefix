#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int node) {
    pq[node].push(-node);
    for (auto neighbor : adj[node]) {
        if (!pq[neighbor].empty() && -pq[neighbor].top() > node) {
            pq[node].push(-pq[neighbor].top());
            pq[neighbor].pop();
        }
    }
    while (pq[node].size() > 10) pq[node].pop();
}

int getKthLargest(int node, int k) {
    if (pq[node].size() < k) return -1;
    auto it = pq[node].begin();
    advance(it, k-1);
    return -(*it);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        updatePQ(i);
    }

    int op, ix, iy;
    for (int i = 0; i < q; ++i) {
        cin >> op >> ix >> iy;
        if (op == 1) {
            addEdge(ix, iy);
            updatePQ(ix);
            updatePQ(iy);
        } else {
            cout << getKthLargest(ix, iy) << '\n';
        }
    }

    return 0;
}