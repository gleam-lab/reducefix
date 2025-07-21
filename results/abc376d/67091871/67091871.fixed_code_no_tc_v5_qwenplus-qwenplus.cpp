#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = 200005;
vector<int> b[200005];
bool vis[200005];

void dfs(int x, int cnt) {
    vis[x] = true;
    if (x == 1 && cnt > 0) { // Found a cycle back to node 1
        mn = min(mn, cnt);
        vis[x] = false; // Allow revisiting node 1 for other paths
        return;
    }
    
    for (int i = 0; i < b[x].size(); i++) {
        int next = b[x][i];
        if (!vis[next]) {
            dfs(next, cnt + 1);
        } else if (next == 1) { // Directly connected back to start
            mn = min(mn, cnt + 1);
        }
    }
    
    vis[x] = false; // Backtrack
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    
    memset(vis, false, sizeof(vis));
    dfs(1, 0);
    
    if (mn == 200005) {
        cout << -1;
    } else {
        cout << mn;
    }
    
    return 0;
}