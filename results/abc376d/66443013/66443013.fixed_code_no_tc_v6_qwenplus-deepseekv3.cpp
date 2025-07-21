#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,bool>visited;
const ll inf=1LL<<60;
ll ans=inf;

void dfs(ll current, ll start, ll depth) {
    visited[current] = true;
    for (auto neighbor : graph[current]) {
        if (neighbor == start && depth > 1) {
            ans = min(ans, depth + 1);
            continue;
        }
        if (!visited[neighbor]) {
            dfs(neighbor, start, depth + 1);
        }
    }
    visited[current] = false; // Backtrack
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    dfs(1, 1, 0);
    if (ans != inf) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}