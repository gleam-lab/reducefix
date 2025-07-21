#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN];
int n, m, start;
int dist[MAXN], prev[MAXN];

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + MAXN, 1e9);
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < d) continue;

        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dijkstra(1);

    if (dist[1] == 1e9) {
        printf("-1");
    } else {
        printf("%d", dist[1]);
    }

    return 0;
}