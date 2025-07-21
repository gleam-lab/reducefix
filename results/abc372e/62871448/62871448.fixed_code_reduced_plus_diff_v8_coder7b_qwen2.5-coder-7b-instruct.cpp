#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int degree[MAXN];

void dfs(int node, int parent, vector<int>& ans) {
    if(degree[node] > ans.size())
        ans.push_back(node);
    else
        ans[degree[node]] = max(ans[degree[node]], node);

    for(auto child : adj[node]) {
        if(child != parent) {
            degree[child]++;
            dfs(child, node, ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> sortedVertices(n + 1);
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
        dfs(i, -1, sortedVertices[i]);
    }

    while(q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if(type == 1) {
            // No need to handle add edge operation in this problem
        } else {
            if(k > sortedVertices[v].size()) cout << "-1" << '\n';
            else cout << sortedVertices[v][k - 1] << '\n';
        }
    }

    return 0;
}