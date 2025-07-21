#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> adj[200005];
int dist[200005], dist2[200005], val[200005], n, m;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = val[start];

    while (!pq.empty()) {
        int curNode = pq.top().second;
        int distFromStart = pq.top().first;
        pq.pop();

        if (distFromStart > dist[curNode]) continue;

        for (auto& [neighbor, weight] : adj[curNode]) {
            int nextNode = neighbor;
            int nextDist = dist[curNode] + val[nextNode] + weight;
            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &val[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(dist, 0x3f, sizeof(dist)); // Use memset for initialization
    dijkstra(1); // Only need to run Dijkstra from node 1

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}