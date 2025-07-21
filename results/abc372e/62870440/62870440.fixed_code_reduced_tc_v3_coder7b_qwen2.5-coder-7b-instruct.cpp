#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

vector<int> adj[MAXN];

void dfs(int node, int parent) {
    if(parent != -1) {
        adj[parent].push_back(node);
        adj[node].push_back(parent);
    }
    for(auto child : adj[node]) {
        if(child == parent) continue;
        dfs(child, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    vector<vector<int>> ans(q);
    
    // Build the tree using DFS
    dfs(1, -1);

    for(int i = 0; i < q; ++i) {
        int type; cin >> type;
        if(type == 1) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            int v, k; cin >> v >> k;
            set<int> s;
            function<void(int)> dfs2 = [&](int node) {
                for(auto child : adj[node]) {
                    if(s.size() >= k && s.rbegin()->second > node) return;
                    dfs2(child);
                    if(s.size() < k || s.rbegin()->second < node) {
                        s.insert({node, node});
                    }
                }
            };
            dfs2(v);
            if(k > s.size()) ans[i].push_back(-1);
            else ans[i].push_back((*s.rbegin()).first);
        }
    }

    for(auto &v : ans) {
        if(!v.empty()) cout << v.front() << '\n';
    }

    return 0;
}