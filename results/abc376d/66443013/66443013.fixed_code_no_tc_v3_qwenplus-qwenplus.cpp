#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> seen;
const ll inf = 1LL << 60;
ll ans = inf;

void dfs(ll n, ll dist) {
    seen[n] = true;

    for (auto x : graph[n]) {
        if (x == 1 && dist + 1 >= 2) { // to avoid self-loop of length 1
            ans = min(ans, dist + 1);
            continue;
        }

        if (!seen[x]) {
            dfs(x, dist + 1);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        if (!seen.count(a)) seen[a] = false;
        if (!seen.count(b)) seen[b] = false;
    }

    dfs(1, 0); // start from node 1 with distance 0

    if (ans != inf) cout << ans << endl;
    else cout << -1 << endl;
}