#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
    if (pq[u].size() > 10) pq[u].pop();
    if (pq[v].size() > 10) pq[v].pop();
}

int getKthLargest(int v, int k) {
    if (k > pq[v].size()) return -1;
    return pq[v].top();
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        if (op == 1) {
            addEdge(ix, iy);
        } else {
            cout << getKthLargest(ix, iy) << "\n";
        }
    }
    return 0;
}