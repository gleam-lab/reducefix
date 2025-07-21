#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node, int &minCycleLen) {
    stack<int> path;
    path.push(node);
    visited[node] = true;
    
    while (!path.empty()) {
        int u = path.top();
        if (adj[u].empty()) {
            path.pop();
        } else {
            int v = adj[u].back();
            adj[u].pop_back();
            
            if (!visited[v]) {
                visited[v] = true;
                path.push(v);
            } else if (v == node) {
                int cycleLen = 0;
                int tempNode = u;
                do {
                    cycleLen++;
                    tempNode = path.top();
                    path.pop();
                } while (tempNode != u);
                
                minCycleLen = min(minCycleLen, cycleLen);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int minCycleLen = INT_MAX;
    memset(visited, false, sizeof(visited));
    
    for(int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, minCycleLen);
        }
    }
    
    if (minCycleLen == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minCycleLen << endl;
    }

    return 0;
}