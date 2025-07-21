#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
vector<vector<pll>> g(MAXN);
ll A[MAXN], dis[MAXN];
bool vis[MAXN];

void dijkstra() {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    fill(dis, dis + MAXN, LLONG_MAX);
    fill(vis, vis + MAXN, false);

    dis[1] = A[1];
    pq.push({dis[1], 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto& [v, w] : g[u]) {
            if (!vis[v] && dis[v] > d + w) {
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }

    dijkstra();

    for (int i = 2; i <= N; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}