#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];

void dfs(int node, int par) {
    if(par != -1) adj[node].push_back(par);
    for(auto child : adj[node]) {
        if(child == par) continue;
        dfs(child, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> queries(q);
    for(int i = 0; i < q; ++i) {
        cin >> queries[i][0];
        if(queries[i][0] == 1) {
            cin >> queries[i][1] >> queries[i][2];
        } else {
            cin >> queries[i][1] >> queries[i][2];
        }
    }
    
    // Build tree structure
    vector<bool> visited(n + 1, false);
    stack<int> st;
    st.push(1);
    visited[1] = true;
    while(!st.empty()) {
        int node = st.top();
        bool flag = false;
        for(int i = 1; i <= n; ++i) {
            if(!visited[i] && adj[node].size() > 0 && find(adj[node].begin(), adj[node].end(), i) != adj[node].end()) {
                visited[i] = true;
                st.push(i);
                flag = true;
                break;
            }
        }
        if(!flag) st.pop();
    }
    
    // Answer queries
    for(auto &query : queries) {
        if(query[0] == 1) {
            adj[query[1]].push_back(query[2]);
            adj[query[2]].push_back(query[1]);
        } else {
            int u = query[1], k = query[2];
            vector<int> neighbors;
            for(auto neighbor : adj[u]) {
                if(neighbor != u) neighbors.push_back(neighbor);
            }
            sort(neighbors.begin(), neighbors.end());
            if(k > neighbors.size()) cout << "-1" << endl;
            else cout << neighbors[k - 1] << endl;
        }
    }
    
    return 0;
}