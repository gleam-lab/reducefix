#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent) {
    pq[node].push(node);
    for(auto child : adj[node]) {
        if(child == parent) continue;
        dfs(child, node);
        while(!pq[child].empty()) {
            pq[node].push(pq[child].top());
            pq[child].pop();
        }
    }
    while(pq[node].size() > 10) pq[node].pop();
}

int kthLargest(int node, int k) {
    if(k > pq[node].size()) return -1;
    return pq[node].nth_element(pq[node].begin(), pq[node].begin()+k-1, pq[node].end()), pq[node][k-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) {
            addEdge(u, v);
        } else {
            cout << kthLargest(u, v) << '\n';
        }
    }
    return 0;
}