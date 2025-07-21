#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
priority_queue<int> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int v, int k) {
    while (!pq[v].empty() && pq[v].top() >= k) {
        pq[v].pop();
    }
    if (pq[v].size() < 10) {
        pq[v].push(k);
    }
}

int getKthLargest(int v, int k) {
    return pq[v].size() >= k ? pq[v].top() : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            addEdge(u, v);
            updatePQ(u, v);
            updatePQ(v, u);
        } else {
            cout << getKthLargest(v, k) << "\n";
        }
    }
    
    return 0;
}