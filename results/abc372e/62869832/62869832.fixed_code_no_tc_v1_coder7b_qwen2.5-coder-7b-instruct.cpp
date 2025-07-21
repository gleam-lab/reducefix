#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
}

int getKthLargest(int v, int k) {
    while (pq[v].size() > k) pq[v].pop();
    if (pq[v].size() < k) return -1;
    return pq[v].top();
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        pq[i].push(-1); // Initialize with a dummy value
    }
    for (int i = 0; i < q; ++i) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        if (op == 1) {
            addEdge(ix, iy);
        } else {
            cout << getKthLargest(ix, iy) << '\n';
        }
    }
    return 0;
}