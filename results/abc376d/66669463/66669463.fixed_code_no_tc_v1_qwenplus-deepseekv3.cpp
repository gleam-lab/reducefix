#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN];
int dist[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++i) {
        dist[i] = INT_MAX;
    }
    
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    queue<pair<int,int>> q; // {node, parent}
    dist[1] = 0;
    q.push({1, -1});
    
    int min_cycle = INT_MAX;
    
    while(!q.empty()) {
        auto current = q.front();
        q.pop();
        int u = current.first;
        int parent = current.second;
        
        for(int v : adj[u]) {
            if(v == 1 && parent != 1) { // Found a cycle back to 1
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }
    
    if(min_cycle == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << min_cycle << endl;
    }
    
    return 0;
}