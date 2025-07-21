#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int src, vector<bool>& visited, priority_queue<int>& pq){
    visited[src] = true;
    for(auto& neighbor : adj[src]){
        if(!visited[neighbor]){
            pq.push(-neighbor); // Push negated value to simulate max heap using min heap
            dfs(neighbor, visited, pq);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            vector<bool> visited(n + 1, false);
            priority_queue<int> pq;
            dfs(v, visited, pq);
            if(k > pq.size()) cout << "-1\n";
            else {
                for(int i = 0; i < k - 1; ++i) pq.pop();
                cout << -pq.top() << '\n'; // Negate back to get the actual value
            }
        }
    }

    return 0;
}