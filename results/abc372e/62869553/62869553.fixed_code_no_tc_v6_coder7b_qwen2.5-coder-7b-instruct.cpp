#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];
int n, q;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int node) {
    pq[node].push(node);
    for (int neighbor : adj[node]) {
        if (!pq[neighbor].empty()) {
            pq[node].push(pq[neighbor].top());
            pq[neighbor].pop();
        }
    }
    while (pq[node].size() > 10) pq[node].pop();
}

int getKthLargest(int node, int k) {
    return pq[node].size() >= k ? pq[node].nth_element(k - 1) : -1;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        if (op == 1) {
            addEdge(ix, iy);
            updatePQ(ix);
            updatePQ(iy);
        } else {
            cout << getKthLargest(ix, iy) << "\n";
        }
    }
    return 0;
}