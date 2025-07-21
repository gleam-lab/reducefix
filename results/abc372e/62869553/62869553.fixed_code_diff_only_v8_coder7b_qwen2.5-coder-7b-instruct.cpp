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

int findKthLargest(int v, int k) {
    if (pq[v].size() < k) return -1;
    while (--k > 0) pq[v].pop();
    return -pq[v].top();
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            addEdge(u, v);
        } else {
            cout << findKthLargest(u, v) << '\n';
        }
    }
    
    return 0;
}