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
    while (k--) {
        int top = pq[v].top();
        pq[v].pop();
    }
    return pq[v].top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= q; ++i) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            cin >> u >> k;
            cout << kthLargest(u, k) << "\n";
        }
    }
    return 0;
}