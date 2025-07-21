#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18

typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

vector<PII> G[N];

int D[N];

void dijkstra(int src) {
    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    memset(D, 0x3f, sizeof(D));
    D[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        
        if (dist > D[u]) continue;
        
        for (auto &[v, w] : G[u]) {
            LL new_dist = dist + w + D[v];
            if (new_dist < D[v]) {
                D[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> D[i];
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= n; i++) cout << D[i] << " ";
    
    return 0;
}