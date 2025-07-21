#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePriorityQueue(int u, int v) {
    pq[u].pop();
    pq[u].push(v);
    while(pq[u].size() > 10) pq[u].pop();
}

void dfs(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        updatePriorityQueue(u, v);
    }
}

int getKthLargest(int u, int k) {
    return pq[u].size() >= k ? pq[u].nth_element(k - 1) : -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) pq[i].push(-1);
    
    while(q--) {
        int type, u, v;
        cin >> type;
        if(type == 1) {
            cin >> u >> v;
            addEdge(u, v);
            updatePriorityQueue(u, v);
            updatePriorityQueue(v, u);
        } else {
            cin >> u >> v;
            cout << getKthLargest(u, v) << '\n';
        }
    }

    return 0;
}