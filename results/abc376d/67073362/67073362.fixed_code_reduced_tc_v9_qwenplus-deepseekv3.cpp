#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int dist[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    queue<pair<int, int>> q; // {node, distance from node 1}
    q.push({1, 0});
    dist[1] = 0;
    
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, d + 1);
            }
            if (dist[v] == -1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
    
    if (min_cycle == INT_MAX) {
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
        fill(dist, dist + N, -1);
        solve();
    }
    return 0;
}