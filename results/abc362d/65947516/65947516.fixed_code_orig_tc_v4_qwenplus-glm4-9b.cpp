#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 2e5 + 5;

int n, m;
long long a[N];
long long dis[N];
bool vis[N];

struct Edge {
    int to, weight;
};

vector<Edge> graph[N];

using Pair = pair<long long, int>;

void dijkstra(int source) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    memset(dis, INT64_MAX, sizeof(dis));
    dis[source] = a[source];

    pq.push({dis[source], source});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (Edge &edge : graph[u]) {
            int v = edge.to;
            long long weight = edge.weight + a[v];

            if (dis[v] > weight) {
                dis[v] = weight;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}