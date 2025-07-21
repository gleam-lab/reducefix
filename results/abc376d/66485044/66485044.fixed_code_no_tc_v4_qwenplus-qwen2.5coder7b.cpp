#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<ll> vec[MAXN];
queue<ll> q;
ll step[MAXN];
bool vis[MAXN];

int main() {
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= m; i++) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    q.push(1);
    step[1] = 0; // Initialize the step of node 1 as 0
    vis[1] = true; // Mark node 1 as visited
    while (!q.empty()) {
        ll top = q.front();
        q.pop();
        for (ll i = 0; i < vec[top].size(); i++) {
            ll to = vec[top][i];
            if (!vis[to]) {
                step[to] = step[top] + 1; // Update the step of node 'to'
                q.push(to);
                vis[to] = true; // Mark node 'to' as visited
            }
        }
    }
    if (vis[n]) { // Check if node 'n' is reachable from node 1
        printf("%lld\n", step[n]); // Print the minimum steps required to reach node 'n'
    } else {
        printf("-1\n"); // Print -1 if node 'n' is not reachable from node 1
    }
    return 0;
}