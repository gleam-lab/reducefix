#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent){
    pq[node].push(node);
    for(auto child : adj[node]){
        if(child != parent){
            dfs(child, node);
            while(!pq[child].empty()){
                int val = pq[child].top();
                pq[child].pop();
                pq[node].push(val);
                if(pq[node].size() > 10){
                    pq[node].pop();
                }
            }
        }
    }
}

int getKthLargest(int node, int k){
    if(k > pq[node].size()) return -1;
    priority_queue<int, vector<int>, greater<int>> temp = pq[node];
    for(int i = 1; i < k; i++){
        temp.pop();
    }
    return temp.top();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        pq[i].push(-1);
    }
    for(int i = 0; i < m; i++){
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1){
            addEdge(u, v);
        } else {
            cout << getKthLargest(u, v) << "\n";
        }
    }
    return 0;
}