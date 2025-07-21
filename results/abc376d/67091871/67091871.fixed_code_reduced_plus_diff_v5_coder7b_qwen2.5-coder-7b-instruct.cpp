#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node, int parent, int &minDist) {
    visited[node] = true;
    for(auto neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, node, minDist);
        } else if(neighbor != parent) {
            minDist = min(minDist, abs(node - neighbor));
        }
    }
}

int findMinDistance(int n) {
    memset(visited, false, sizeof(visited));
    int minDist = INT_MAX;
    dfs(1, -1, minDist);
    return minDist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << findMinDistance(n) << endl;

    return 0;
}