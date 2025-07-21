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

int kthLargest(int v, int k) {
    while (!pq[v].empty() && pq[v].size() > k) pq[v].pop();
    if (pq[v].size() < k) return -1;
    return pq[v].top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        addEdge(i, i); // Initialize each node to connect with itself
    }

    int op, ix, iy;
    for (int i = 0; i < q; ++i) {
        cin >> op >> ix >> iy;
        if (op == 1) {
            addEdge(ix, iy);
        } else {
            cout << kthLargest(ix, iy) << "\n";
        }
    }

    return 0;
}