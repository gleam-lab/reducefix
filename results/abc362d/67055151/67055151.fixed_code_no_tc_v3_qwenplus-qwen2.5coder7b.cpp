#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int INF = 1e9 + 7;

vector<int> adj[MAXN];
vector<int> cost(MAXN);
vector<long long> dis(MAXN, INF);

void dijkstra(int src, int n) {
    set<pair<long long, int>> st;
    st.insert({cost[src], src});

    while (!st.empty()) {
        auto [dist, u] = *(st.begin());
        st.erase(st.begin());

        if (dis[u] != dist) continue;

        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                st.erase({dis[v], v});
                dis[v] = dis[u] + w;
                st.insert({dis[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> cost[i];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(0, n);

    for (int i = 1; i < n; ++i) {
        cout << dis[i] << " ";
    }
    cout << "\n";

    return 0;
}