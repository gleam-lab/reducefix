#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent, vector<int>& degree, vector<vector<int>>& bucket){
    for(auto child : adj[node]){
        if(child != parent){
            dfs(child, node, degree, bucket);
            degree[node] += degree[child];
            bucket[degree[node]].push_back(node);
        }
    }
    degree[node]++;
}

void preprocess(vector<int>& degree, vector<vector<int>>& bucket){
    for(int i = 1; i <= 2 * MAXN; ++i){
        sort(bucket[i].begin(), bucket[i].end());
    }
}

int findKthLargest(int node, int k, vector<int>& degree, vector<vector<int>>& bucket){
    int level = degree[node];
    if(k > bucket[level].size()){
        return -1;
    }
    return bucket[level][bucket[level].size() - k];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    
    vector<int> degree(n + 1, 0);
    vector<vector<int>> bucket(MAXN);

    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    dfs(1, 0, degree, bucket);
    preprocess(degree, bucket);

    while(q--){
        int type, v, k;
        cin >> type >> v >> k;
        if(type == 1){
            // No need to handle type 1 query here as it only adds edges and does not affect the solution.
        } else {
            cout << findKthLargest(v, k, degree, bucket) << '\n';
        }
    }

    return 0;
}