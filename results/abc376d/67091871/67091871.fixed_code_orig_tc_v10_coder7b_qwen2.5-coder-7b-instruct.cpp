#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int node, int &minDist) {
    if (!vis[node]) {
        vis[node] = true;
        for (auto neighbor : adj[node]) {
            dfs(neighbor, minDist);
            minDist = min(minDist, abs(node - neighbor));
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int minDist = INT_MAX;
    dfs(1, minDist);
    cout << minDist << endl;
    return 0;
}