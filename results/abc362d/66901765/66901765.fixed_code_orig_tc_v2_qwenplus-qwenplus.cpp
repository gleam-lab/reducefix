#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

vector<vector<pair<int, int>>> G(200005);
int dis[200005];
bool vis[200005];
int A[200005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    dis[start] = A[start];
    pq.push({dis[start], start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto [v, w] : G[u]) {
            if (dis[v] > d + A[v] + w) {
                dis[v] = d + A[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dis[i] = INF;
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << dis[i] << " ";
    }
    cout << "\n";
    
    return 0;
}