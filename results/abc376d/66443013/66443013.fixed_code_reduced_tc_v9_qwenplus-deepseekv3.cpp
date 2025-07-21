#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, vector<ll>> graph;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    ll ans = -1;
    queue<pair<ll, ll>> q; // {node, distance}
    q.push({1, 0});
    map<ll, ll> dist;
    dist[1] = 0;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        ll u = current.first;
        ll d = current.second;

        for (auto v : graph[u]) {
            if (v == 1) {
                if (d + 1 >= 1) {
                    if (ans == -1 || d + 1 < ans) {
                        ans = d + 1;
                    }
                }
                continue;
            }
            if (!dist.count(v) || d + 1 < dist[v]) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }

    cout << ans << endl;
    return 0;
}