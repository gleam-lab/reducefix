#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
ll dist[MAXN];
bool vis[MAXN];

int main() {
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= m; i++) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    
    memset(dist, -1, sizeof(dist));
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    ll min_cycle = INF;
    
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        
        for (ll v : vec[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    if (min_cycle != INF) {
        printf("%lld\n", min_cycle);
    } else {
        printf("-1\n");
    }
    
    return 0;
}