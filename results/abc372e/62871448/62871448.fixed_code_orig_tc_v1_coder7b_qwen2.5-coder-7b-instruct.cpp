#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
priority_queue<int> pq[MAXN];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent){
    pq[node].push(node);
    for(auto child: adj[node]){
        if(child == parent) continue;
        dfs(child, node);
        while(pq[child].size() > 10) pq[child].pop();
        while(!pq[child].empty()){
            pq[node].push(pq[child].top());
            pq[child].pop();
            if(pq[node].size() > 10) pq[node].pop();
        }
    }
}

int getKthLargest(int node, int k){
    if(k > pq[node].size()) return -1;
    auto temp = pq[node];
    while(--k >= 0) temp.pop();
    return temp.top();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n-1; ++i){
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }
    
    dfs(1, -1);
    
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int u, v; cin >> u >> v;
            addEdge(u, v);
            dfs(u, -1);
            dfs(v, -1);
        } else {
            int v, k; cin >> v >> k;
            cout << getKthLargest(v, k) << '\n';
        }
    }
    
    return 0;
}