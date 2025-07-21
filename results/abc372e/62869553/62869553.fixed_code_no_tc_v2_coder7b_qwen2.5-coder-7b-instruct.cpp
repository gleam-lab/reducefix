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
    if (pq[v].size() < k) return -1;
    for (int i = 1; i <= k - 1; ++i) pq[v].pop();
    int result = pq[v].top();
    while (!pq[v].empty()) pq[v].pop();
    return result;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < q; ++i) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            addEdge(u, v);
        } else {
            cout << kthLargest(u, v) << endl;
        }
    }
    
    return 0;
}