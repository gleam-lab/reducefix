#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2 * 100005;

bool visited[MAXN];
int dist[MAXN];

vector<int> adj[MAXN];

// Function to perform DFS and detect cycle
bool dfs(int node, int parent) {
    visited[node] = true;
    
    for(auto neighbor : adj[node]) {
        // If not visited, recursively visit
        if(!visited[neighbor]) {
            dist[neighbor] = dist[node] + 1;
            if(dfs(neighbor, node)) return true;
        } 
        // If visited and not parent, then cycle detected
        else if(neighbor != parent && dist[neighbor] < dist[node]) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    bool hasCycle = false;
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            dist[i] = 0;
            if(dfs(i, -1)) {
                hasCycle = true;
                break;
            }
        }
    }

    if(hasCycle) {
        cout << "1\n"; // Minimum length of cycle containing vertex 1 is 1 (the cycle itself)
    } else {
        cout << "-1\n";
    }

    return 0;
}