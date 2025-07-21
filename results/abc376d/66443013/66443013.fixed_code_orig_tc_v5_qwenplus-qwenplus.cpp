#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> visited;
const ll inf = 1LL << 60;
ll ans = inf;

// BFS version to find shortest cycle involving node 1
void bfs(ll start) {
    map<ll, ll> dist;
    queue<ll> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        
        for (auto next : graph[curr]) {
            if (dist.find(next) == dist.end()) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            } else if (next != start) {
                // If already visited and not parent node, check for cycle
                ans = min(ans, dist[curr] + dist[next] + 1);
            }
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
        if (!visited.count(a)) visited[a] = false;
        if (!visited.count(b)) visited[b] = false;
    }

    // Try BFS from node 1
    map<ll, ll> dist;
    queue<ll> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        ll curr = q.front();
        q.pop();

        for (auto next : graph[curr]) {
            if (dist.find(next) == dist.end()) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            } else if (next == 1 && curr != 1) {
                // Found a cycle back to 1
                ans = min(ans, dist[curr] + 1);
            }
        }
    }

    if (ans != inf)
        cout << ans << endl;
    else
        cout << -1 << endl;
}