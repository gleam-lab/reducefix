#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void removeEdge(int u, int v){
    auto it = find(adj[u].begin(), adj[u].end(), v);
    if(it != adj[u].end()){
        adj[u].erase(it);
    }
    it = find(adj[v].begin(), adj[v].end(), u);
    if(it != adj[v].end()){
        adj[v].erase(it);
    }
}

void dfs(int node, int parent){
    pq[node].push(node);
    for(auto child : adj[node]){
        if(child == parent) continue;
        dfs(child, node);
        while(pq[child].size() > 10) pq[child].pop();
        while(!pq[child].empty()){
            pq[node].push(pq[child].top());
            pq[child].pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i){
        dfs(i, -1);
    }

    while(q--){
        int type, u, k;
        cin >> type >> u >> k;
        if(type == 1){
            addEdge(u, v);
            dfs(u, -1);
            dfs(v, -1);
        } else {
            if(k > pq[u].size()) cout << "-1" << endl;
            else cout << pq[u].nth_element(k - 1) << endl;
        }
    }

    return 0;
}