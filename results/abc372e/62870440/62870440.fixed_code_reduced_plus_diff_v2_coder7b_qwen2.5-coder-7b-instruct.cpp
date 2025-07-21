#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int v, int val) {
    auto it = find(pq[v].begin(), pq[v].end(), val);
    if(it != pq[v].end()) pq[v].erase(it);
    pq[v].push(val);
    while(pq[v].size() > 10) pq[v].pop();
}

void dfs(int u, int par) {
    for(auto v : adj[u]) {
        if(v == par) continue;
        dfs(v, u);
        for(auto x : pq[v]) pq[u].push(x);
        while(pq[u].size() > 10) pq[u].pop();
    }
    updatePQ(u, u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }

    dfs(1, -1);

    for(int i = 0; i < q; i++) {
        int type, v, k; cin >> type >> v >> k;
        if(type == 2) {
            if(k > pq[v].size()) cout << -1 << "\n";
            else cout << pq[v].top() << "\n";
        }
    }

    return 0;
}