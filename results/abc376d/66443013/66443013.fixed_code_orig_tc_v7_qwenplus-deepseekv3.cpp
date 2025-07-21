#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll inf=1LL<<60;

ll findShortestCycle(ll n, map<ll, vector<ll>>& graph) {
    ll ans = inf;
    vector<ll> dist(n+1, -1);
    queue<ll> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : graph[u]) {
            if (v == 1) {
                ans = min(ans, dist[u] + 1);
                continue;
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return ans == inf ? -1 : ans;
}

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, vector<ll>> graph;

    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    ll result = findShortestCycle(n, graph);
    cout << result << endl;

    return 0;
}