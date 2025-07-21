#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int node) {
    pq[node].push(node);
    for(auto neighbor : adj[node]) {
        if(pq[neighbor].size() > 10) pq[neighbor].pop();
        pq[neighbor].push(node);
    }
}

int kthLargest(int node, int k) {
    if(k > pq[node].size()) return -1;
    auto it = pq[node].begin();
    advance(it, k-1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        updatePQ(i);
    }

    while(q--) {
        int type, u, v; cin >> type >> u >> v;
        if(type == 1) {
            addEdge(u, v);
            updatePQ(u);
            updatePQ(v);
        } else {
            cout << kthLargest(u, v) << '\n';
        }
    }

    return 0;
}