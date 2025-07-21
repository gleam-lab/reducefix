#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,bool>seen;
const ll inf=1LL<<60;
ll ans=inf;
bool found = false;

void dfs(ll n, ll hen) {
    if(found) return; // Early termination if answer has already been found
    seen[n] = true;
    for (auto x : graph[n]) {
        if (x != 1 && seen[x]) continue;
        if (x == 1) {
            if (hen != 1) {
                ans = min(ans, hen + 1);
                found = true; // Set flag once answer is found
            }
            continue;
        }
        dfs(x, hen + 1);
    }
    seen[n] = false; // Reset seen status after recursion
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        if (!seen.count(a)) seen[a] = false;
        if (!seen.count(b)) seen[b] = false;
    }
    dfs(1, 0);
    if (ans == inf) cout << "-1" << endl;
    else cout << ans << endl;
}