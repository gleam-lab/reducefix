#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
queue<ll> q;
ll step[MAXN];
bool vis[MAXN];

void BFS(ll start) {
    q.push(start);
    step[start] = 0;
    vis[start] = true;
    while (!q.empty()) {
        ll top = q.front();
        q.pop();
        for (ll i = 0; i < vec[top].size(); i++) {
            ll to = vec[top][i];
            if (!vis[to]) {
                step[to] = step[top] + 1;
                q.push(to);
                vis[to] = true;
            }
        }
    }
}

int main() {
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for (ll i = 0; i < m; i++) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    BFS(1);
    for (ll i = 1; i <= n; i++) {
        printf("%lld ", step[i]);
    }
    return 0;
}