#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent, vector<vector<int>>& dp){
    sort(adj[node].begin(), adj[node].end());
    dp[node][0] = node;
    for(auto child : adj[node]){
        if(child != parent){
            dfs(child, node, dp);
            for(int i = 0; i < 10 && dp[child][i] != -1; ++i){
                dp[node][i + 1] = dp[child][i];
            }
        }
    }
}

int queryKthLargest(vector<vector<int>>& dp, int node, int k){
    int idx = log2(k);
    return dp[node][idx];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> dp(n + 1, vector<int>(10, -1));
    
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    dfs(1, -1, dp);

    while(q--){
        int type, node, k;
        cin >> type >> node >> k;
        if(type == 2){
            cout << queryKthLargest(dp, node, k) << '\n';
        }
    }

    return 0;
}