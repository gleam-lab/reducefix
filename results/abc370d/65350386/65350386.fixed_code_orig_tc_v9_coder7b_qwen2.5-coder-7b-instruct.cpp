#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> adj(400001);

void addEdge(int u, int v){
    adj[u].push_back({v, 0});
    adj[v].push_back({u, 1});
}

int dfs(int src, int par, int dir){
    if(adj[src].size() == 1 && adj[src][0].first == par)
        return 0;
    int cnt = 0;
    for(auto [nei, _] : adj[src]){
        if(nei == par) continue;
        cnt += dfs(nei, src, dir);
    }
    if(dir == 0)
        ++cnt;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=m;++i){
        addEdge(n+i, 2*n+i);
        addEdge(2*n+i, 3*n+i);
        addEdge(3*n+i, n+i);
    }
    for(int i=1;i<=n;++i){
        addEdge(4*n+i, i);
        addEdge(4*n+i, n+i);
        addEdge(4*n+i, 2*n+i);
        addEdge(4*n+i, 3*n+i);
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            addEdge(i, j);
            addEdge(j, i);
        }
    }
    vector<bool> vis(m+1, false);
    while(q--){
        int x;
        cin >> x;
        --x;
        if(!vis[x]){
            vis[x] = true;
            dfs(x, -1, 0);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        int cnt = dfs(i, -1, 0);
        ans += cnt*(cnt-1)/2;
    }
    cout << ans << '\n';
    return 0;
}