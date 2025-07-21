#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int dist[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    queue<int> q;
    
    // Start BFS from node 1
    dist[1] = 1;
    q.push(1);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(v == 1) {
                min_cycle = min(min_cycle, dist[u]);
            }
            if(!dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    cout << (min_cycle == INT_MAX ? -1 : min_cycle) << endl;
    
    return 0;
}