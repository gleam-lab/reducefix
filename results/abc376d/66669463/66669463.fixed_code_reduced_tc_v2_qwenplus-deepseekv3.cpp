#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    vector<int> distance(n + 1);
    queue<int> q;
    
    for (int neighbor : adj[1]) {
        if (neighbor == 1) {
            min_cycle = 1;
            break;
        }
        distance.assign(n + 1, -1);
        distance[neighbor] = 1;
        q.push(neighbor);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (v == 1) {
                    min_cycle = min(min_cycle, distance[u] + 1);
                    continue;
                }
                if (distance[v] == -1) {
                    distance[v] = distance[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    cout << (min_cycle == INT_MAX ? -1 : min_cycle) << '\n';
    return 0;
}