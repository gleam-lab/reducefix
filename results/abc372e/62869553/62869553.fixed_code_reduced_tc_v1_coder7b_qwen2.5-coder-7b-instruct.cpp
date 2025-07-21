#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int degree[MAXN], parent[MAXN];

void dfs(int node, int par) {
    parent[node] = par;
    for(auto child : adj[node]) {
        if(child != par) {
            degree[child]++;
            dfs(child, node);
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    dfs(1, -1);
    
    while(q--) {
        int type, v, k;
        cin >> type >> v;
        
        if(type == 1) {
            int u;
            cin >> u;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        } else {
            vector<int> children;
            for(auto child : adj[v]) {
                if(degree[child] > 0) {
                    children.push_back(child);
                }
            }
            
            sort(children.begin(), children.end());
            
            if(k <= children.size()) {
                cout << children[k-1] << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}