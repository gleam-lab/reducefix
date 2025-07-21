#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int,vector<int>,greater<int>> pq[200005];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int node){
    pq[node].push(node);
    for(auto &child : adj[node]){
        if(pq[child].size() > 9) pq[child].pop();
        pq[child].push(node);
    }
}

int findKthLargest(int node, int k){
    while(k-- && !pq[node].empty()){
        node = pq[node].top(); pq[node].pop();
    }
    return pq[node].empty() ? -1 : node;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    
    for(int i=1; i<=n; ++i){
        addEdge(i, i);
        updatePQ(i);
    }

    for(int i=0; i<q; ++i){
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1){
            addEdge(u, v);
            updatePQ(u); updatePQ(v);
        } else {
            cout << findKthLargest(v, k) << "\n";
        }
    }
    return 0;
}