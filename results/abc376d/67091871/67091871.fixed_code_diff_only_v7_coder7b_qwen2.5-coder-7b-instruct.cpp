#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200005;
ll n,m,mn=INT_MAX,vis[N];
vector<int> b[N];

void dfs(int x, int cnt) {
    vis[x] = 1;
    for(int i = 0; i < b[x].size(); i++) {
        if(!vis[b[x][i]]) {
            dfs(b[x][i], cnt + 1);
        }
    }
    // Check if we have visited all nodes connected to node 1
    if(cnt == m - 1 && x != 1) {
        mn = min(mn, cnt + 1);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
        b[v].push_back(u); // Assuming undirected graph
    }
    dfs(1, 0);
    if(mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}