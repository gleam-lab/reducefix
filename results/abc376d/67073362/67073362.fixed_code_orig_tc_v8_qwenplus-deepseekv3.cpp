#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int dist[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    
    // Perform BFS from node 1 to find shortest cycle back to 1
    queue<pair<int, int>> q;
    q.push({1, 0});
    
    for(int i = 1; i <= n; i++) dist[i] = -1;
    dist[1] = 0;
    
    while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(v == 1) {
                min_cycle = min(min_cycle, d + 1);
                continue;
            }
            if(dist[v] == -1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
    
    if(min_cycle == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
    
    return 0;
}