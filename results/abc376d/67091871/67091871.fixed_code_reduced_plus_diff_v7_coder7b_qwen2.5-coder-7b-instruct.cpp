#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;
bool visited[MAXN];
vector<int> adj[MAXN];

void dfs(int node, int parent) {
    visited[node] = true;
    for(auto child : adj[node]) {
        if(child != parent && !visited[child]) {
            dfs(child, node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    dfs(1, -1);

    bool isTree = true;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            isTree = false;
            break;
        }
    }

    if(isTree) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}