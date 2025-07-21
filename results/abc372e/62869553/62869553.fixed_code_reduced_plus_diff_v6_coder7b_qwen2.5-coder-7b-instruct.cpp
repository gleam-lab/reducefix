#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int degree[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
}

void updateDegree(int u, int v) {
    if(degree[u] > 1) pq[u].pop();
    if(degree[v] > 1) pq[v].pop();
    degree[u]--;
    degree[v]--;
    if(degree[u]) pq[u].push(u);
    if(degree[v]) pq[v].push(v);
}

int kthLargest(int u, int k) {
    while(k--) {
        if(pq[u].size() == 0 || pq[u].top() != u) return -1;
        u = pq[u].top();
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; ++i) {
        pq[i].push(i);
    }
    
    for(int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if(type == 1) {
            addEdge(u, v);
        } else {
            cout << kthLargest(u, v) << "\n";
        }
    }
    
    return 0;
}