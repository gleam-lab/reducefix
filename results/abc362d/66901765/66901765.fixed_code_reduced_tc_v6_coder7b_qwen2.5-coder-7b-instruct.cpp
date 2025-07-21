#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<pair<int, int>> G[200005];
int n, m, a[200005], dis[200005];

// Function to perform Dijkstra's algorithm
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dis, dis + n + 1, INF);
    dis[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > dis[u]) continue;

        for (auto [v, w] : G[u]) {
            if (dis[u] + a[v] + w < dis[v]) {
                dis[v] = dis[u] + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    printf("\n");

    return 0;
}