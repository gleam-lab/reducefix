#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<pair<ll, ll>> vec[MAXN]; // Use pair to store both node and distance
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // Min-heap for processing nodes based on distance
ll dist[MAXN];
bool vis[MAXN];

int main() {
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for (ll i = 0; i < m; i++) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back({v, 1}); // Assuming all edges have weight 1
        vec[v].push_back({u, 1});
    }
    
    pq.push({1, 0}); // Start from node 1 with distance 0
    dist[1] = 0;
    vis[1] = true;

    while (!pq.empty()) {
        ll top = pq.top().second;
        pq.pop();
        
        if (top == 1) {
            // If we reach the start node again, check the distance
            if (dist[1] == 0) {
                printf("0");
                return 0;
            } else {
                printf("%lld", dist[1]);
                return 0;
            }
        }
        
        for (auto &p : vec[top]) {
            ll to = p.first;
            if (!vis[to]) {
                vis[to] = true;
                dist[to] = dist[top] + p.second; // Update distance
                pq.push({to, dist[to]});
            }
        }
    }
    
    printf("-1"); // If we didn't find a path
    return 0;
}