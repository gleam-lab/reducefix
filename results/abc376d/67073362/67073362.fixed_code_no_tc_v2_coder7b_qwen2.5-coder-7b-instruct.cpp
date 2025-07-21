#include<iostream>
#include<vector>
#include<algorithm>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
bool visited[MAXN];

bool hasCycle(int node, int parent, int& minEdges) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (hasCycle(neighbor, node, minEdges)) {
                minEdges++;
                return true;
            }
        } else if (neighbor != parent) {
            minEdges++;
            return true;
        }
    }
    return false;
}

int findMinCycleEdges(int n) {
    memset(visited, false, sizeof(visited));
    int minEdges = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            bool foundCycle = hasCycle(i, -1, minEdges);
            if (foundCycle && minEdges > 0) {
                return minEdges;
            }
        }
    }
    return -1;
}

int main() {
    IOS;
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int result = findMinCycleEdges(n);
    cout << result << endl;
    
    return 0;
}