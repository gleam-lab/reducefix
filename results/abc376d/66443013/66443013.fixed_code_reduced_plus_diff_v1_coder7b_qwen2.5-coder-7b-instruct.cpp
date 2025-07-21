#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, vector<ll>> graph;
map<ll, bool> seen;
const ll inf = 1LL << 60;
ll ans = inf;

void dfs(ll node, ll dist) {
    seen[node] = true;
    for (auto neighbor : graph[node]) {
        if (neighbor != 1 && seen[neighbor]) continue;
        if (neighbor == 1) {
            if (dist != 1) {
                ans = min(ans, dist + 1);
            }
            continue;
        }
        dfs(neighbor, dist + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (!seen.count(a)) seen[a] = false;
        if (!seen.count(b)) seen[b] = false;
    }
    dfs(1, 0);
    if (ans != inf) cout << ans << endl;
    else cout << "-1" << endl;
    return 0;
}