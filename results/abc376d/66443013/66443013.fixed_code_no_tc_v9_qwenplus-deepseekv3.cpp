#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    ll ans = -1;
    for (auto neighbor : graph[1]) {
        queue<pair<ll, ll>> q;
        q.push({neighbor, 1});
        vector<bool> visited(n + 1, false);
        visited[neighbor] = true;
        while (!q.empty()) {
            auto [current, dist] = q.front();
            q.pop();
            if (current == 1) {
                ans = (ans == -1) ? dist + 1 : min(ans, dist + 1);
                break;
            }
            for (auto next : graph[current]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, dist + 1});
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}