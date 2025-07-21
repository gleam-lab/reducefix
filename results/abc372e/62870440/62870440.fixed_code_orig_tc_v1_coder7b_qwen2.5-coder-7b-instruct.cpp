#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int deg[MAXN];

void dfs(int u, int p) {
    if(p != -1) {
        deg[u]++;
        deg[p]++;
    }
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
}

priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    dfs(u, -1);
    dfs(v, -1);
}

void updatePQ(int u) {
    pq[u].clear();
    for(auto v : adj[u]) {
        if(deg[v] > 1) pq[u].push(deg[v]);
    }
    sort(pq[u].begin(), pq[u].end());
}

int getKthLargest(int u, int k) {
    if(k > pq[u].size()) return -1;
    return pq[u].back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        addEdge(i, i);
    }

    while(q--) {
        int type, u, k;
        cin >> type >> u >> k;
        if(type == 1) {
            addEdge(u, k);
            updatePQ(u);
            updatePQ(k);
        } else {
            cout << getKthLargest(u, k) << "\n";
        }
    }

    return 0;
}