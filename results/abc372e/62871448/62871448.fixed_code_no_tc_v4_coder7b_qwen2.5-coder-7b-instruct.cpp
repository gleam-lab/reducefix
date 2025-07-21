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

int kthLargest(int u, int k) {
    while (pq[u].size() > k) {
        pq[u].pop();
    }
    if (pq[u].size() < k) return -1;
    return pq[u].top();
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else {
            cin >> u >> k;
            cout << kthLargest(u, k) << "\n";
        }
    }
    return 0;
}