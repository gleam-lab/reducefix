#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> seen;
const ll inf = 1LL << 60;

ll ans = inf;

void dfs(ll n, ll depth) {
    seen[n] = true;

    for (auto x : graph[n]) {
        if (x == 1) {
            ans = min(ans, depth + 1);
            continue;
        }
        if (!seen[x]) {
            dfs(x, depth + 1);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        if (!seen.count(a)) seen[a] = false;
        if (!seen.count(b)) seen[b] = false;
    }

    // Reset seen map and perform DFS from node 1
    for (auto &[k, v] : seen) {
        v = false;
    }

    dfs(1, 1);

    if (ans != inf)
        cout << ans << endl;
    else
        cout << "-1" << endl;
}