#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(-v);
    pq[v].push(-u);
}

int getKthLargest(int v, int k) {
    while(!pq[v].empty() && k--) {
        if(pq[v].top() == -v) {
            pq[v].pop();
            continue;
        }
        return -pq[v].top();
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        pq[i].push(-i);
    }
    while(q--) {
        int op, u, v; cin >> op >> u >> v;
        if(op == 1) {
            addEdge(u, v);
        } else {
            cout << getKthLargest(v, k) << '\n';
        }
    }
    return 0;
}