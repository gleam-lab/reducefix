#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_N = 200005; // æ ¹æ®éè¦è°æ´
vector<pair<int, int>> adj[MAX_N]; // é»æ¥è¡¨
int dist[MAX_N]; // æç­è·ç¦»

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // éå

    fill(dist, dist + MAX_N, INT_MAX); // åå§åè·ç¦»ä¸ºæ ç©·å¤§
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v]) continue; // å¦æå·²ç»ææ´ç­çè·¯å¾ï¼å°±å¿½ç¥è¿ä¸ªè·¯å¾

        for (auto &nei : adj[v]) {
            int weighed = v + nei.first;
            if (dist[v] + nei.first < dist[weighed]) {
                dist[weighed] = dist[v] + nei.first;
                pq.push({dist[weighed], weighed});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    dijkstra(1);

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}