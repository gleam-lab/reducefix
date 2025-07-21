#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long INF = 1e18;
const int N = 2 * 1e5 + 5;

vector<vector<pair<int, long long>>> adj(N);
vector<long long> val(N), dist(N, INF);

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> val[i];

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        auto [dcur, ucur] = pq.top();
        pq.pop();

        if (dcur > dist[ucur]) continue;

        for (auto [v, w] : adj[ucur]) {
            long long ndist = dcur + w + val[v];
            if (ndist < dist[v]) {
                dist[v] = ndist;
                pq.push({ndist, v});
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + val[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}