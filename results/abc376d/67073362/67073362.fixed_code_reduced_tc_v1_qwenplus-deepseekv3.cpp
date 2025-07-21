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
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    
    queue<int> q;
    q.push(1);
    
    int min_cycle = INF;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    cout << (min_cycle == INF ? -1 : min_cycle) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}