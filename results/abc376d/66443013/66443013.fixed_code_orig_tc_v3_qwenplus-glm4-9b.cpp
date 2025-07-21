#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
const ll inf=1LL<<60;

// Utility function to perform DFS
void dfs(ll n, ll hen, ll &ans) {
    seen[n] = true;
    for (auto x : graph[n]) {
        if (x == 1) {
            if (hen != 1 && ans > hen + 1) {
                ans = hen + 1;
            }
        } else if (!seen[x]) {
            dfs(x, hen + 1, ans);
        }
    }
    seen[n] = false;
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    ll ans = inf;
    map<ll, bool> seen;
    dfs(1, 0, ans);
    
    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}