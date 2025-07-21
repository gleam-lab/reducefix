#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int u, int p) {
    for(auto &v : adj[u]) {
        if(v != p) {
            pq[v].push(u);
            if(pq[v].size() > 10) pq[v].pop();
            dfs(v, u);
        }
    }
}

int getKthLargest(int v, int k) {
    if(k > pq[v].size()) return -1;
    return pq[v].top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    dfs(1, -1);

    while(q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if(type == 1) continue;
        cout << getKthLargest(v, k) << '\n';
    }

    return 0;
}