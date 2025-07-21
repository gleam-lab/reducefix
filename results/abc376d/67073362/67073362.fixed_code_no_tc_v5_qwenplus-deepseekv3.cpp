#include<iostream>
#include<queue>
#include<vector>
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
    
    int min_cycle = INF;
    queue<pair<int, int>> q;
    q.push({1, 0});
    
    for (int i = 1; i <= n; i++) dist[i] = -1;
    dist[1] = 0;
    
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, d + 1);
                continue;
            }
            if (dist[v] == -1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
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
    while (T--) {
        solve();
    }
    
    return 0;
}