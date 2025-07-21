#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e18;

vector<pair<int,int>> G[200005];
int dis[200005];
int a[200005];

void dij(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({a[u], u});
    dis[u] = a[u];
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        if (current_dist > dis[current_node]) continue;
        for (auto [v, w] : G[current_node]) {
            int new_dist = current_dist + a[v] + w;
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    fill(dis, dis + N + 1, INF);
    dij(1);
    for (int i = 2; i <= N; ++i) {
        cout << dis[i] << ' ';
    }
    cout << '\n';
    return 0;
}