#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
ll dist[MAXN]; // To store the distance from the source
bool vis[MAXN]; // To check if the vertex is visited

void bfs(ll source, ll n) {
    queue<ll> q;
    q.push(source);
    dist[source] = 0;
    vis[source] = true;
    
    while (!q.empty()) {
        ll top = q.front();
        q.pop();
        
        for (ll i = 0; i < vec[top].size(); i++) {
            ll to = vec[top][i];
            if (!vis[to]) {
                vis[to] = true;
                dist[to] = dist[top] + 1;
                q.push(to);
                if (to == 1) { // If we reach the destination
                    return;
                }
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
        vec[v].push_back(u); // Since the graph is undirected
    }
    bfs(1, n);
    if (dist[1] == INF) {
        printf("-1");
    } else {
        printf("%lld", dist[1]);
    }
    return 0;
}