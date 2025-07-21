#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
}

int getKthLargest(int v, int k) {
    if (pq[v].size() < k) return -1;
    while (pq[v].size() > k) pq[v].pop();
    return pq[v].top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        pq[i].reset();
    }

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            addEdge(u, v);
        } else {
            cout << getKthLargest(u, v) << '\n';
        }
    }

    return 0;
}