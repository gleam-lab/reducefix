#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
const int INF = INT_MAX;

vector<int> adj[N];
int dist[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INF;
    
    // Check all neighbors of node 1 first for direct cycles
    for(int v : adj[1]) {
        if(v == 1) {
            min_cycle = 1;
            break;
        }
    }
    
    if(min_cycle == 1) {
        cout << 1 << endl;
        return;
    }
    
    // BFS for longer cycles
    queue<pair<int, int>> q;
    fill(dist, dist + n + 1, INF);
    
    for(int v : adj[1]) {
        q.push({v, 1});
        dist[v] = 1;
    }
    
    while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(v == 1) {
                min_cycle = min(min_cycle, d + 1);
                continue;
            }
            if(d + 1 < dist[v]) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
    
    if(min_cycle == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}