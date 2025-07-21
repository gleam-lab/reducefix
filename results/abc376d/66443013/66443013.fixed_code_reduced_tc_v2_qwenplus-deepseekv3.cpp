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

    ll ans = -1;
    queue<pair<ll, ll>> q; // {current node, distance from 1}
    q.push({1, 0});
    vector<ll> dist(n + 1, -1);
    dist[1] = 0;

    while (!q.empty()) {
        auto [current, d] = q.front();
        q.pop();
        for (auto neighbor : graph[current]) {
            if (neighbor == 1) {
                if (ans == -1 || d + 1 < ans) {
                    ans = d + 1;
                }
            }
            if (dist[neighbor] == -1) {
                dist[neighbor] = d + 1;
                q.push({neighbor, d + 1});
            }
        }
    }

    cout << ans << endl;
    return 0;
}