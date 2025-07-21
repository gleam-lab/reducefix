#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, vector<ll>> graph;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    ll ans = LLONG_MAX;
    queue<pair<ll, ll>> q; // {current node, distance from start}

    for (auto neighbor : graph[1]) {
        q.push({neighbor, 1});
        map<ll, ll> dist;
        dist[neighbor] = 1;
        while (!q.empty()) {
            auto [current, d] = q.front();
            q.pop();
            for (auto next : graph[current]) {
                if (next == 1) {
                    ans = min(ans, d + 1);
                    continue;
                }
                if (dist.find(next) == dist.end()) {
                    dist[next] = d + 1;
                    q.push({next, d + 1});
                }
            }
        }
    }

    if (ans != LLONG_MAX) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}