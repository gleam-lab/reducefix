#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

struct compare {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

vector<long long> dijkstra(int start, int n, vector<vector<pii>>& adjList) {
    vector<ll> dist(n, LLONG_MAX);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, compare> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        ll d = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adjList[u]) {
            int v = edge.first;
            ll weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pii>> adjList(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u; --v; // Convert to zero-based index
        adjList[u].emplace_back(v, b);
        adjList[v].emplace_back(u, b);
    }

    vector<ll> result = dijkstra(0, n, adjList);

    for (int i = 1; i < n; ++i) {
        cout << result[i] + a[i] << " ";
    }
    cout << endl;

    return 0;
}