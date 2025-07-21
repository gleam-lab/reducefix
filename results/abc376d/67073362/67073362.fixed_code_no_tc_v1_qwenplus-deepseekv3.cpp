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
    
    queue<int> q;
    q.push(1);
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    
    int min_cycle = INF;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    if (min_cycle == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}