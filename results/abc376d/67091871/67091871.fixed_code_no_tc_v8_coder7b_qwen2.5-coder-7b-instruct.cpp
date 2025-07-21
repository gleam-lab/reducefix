#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;
vector<int> adj[N];
bool vis[N];
int mn = INT_MAX;

void dfs(int node, int dist) {
    if (dist > mn) return; // Early exit if current distance exceeds minimum found so far
    vis[node] = true;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, dist + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    dfs(1, 0); // Start DFS from node 1 with initial distance 0

    if (mn == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << mn << '\n';
    }

    return 0;
}