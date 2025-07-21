#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18

typedef pair<LL, LL> pl;
typedef pair<LL, pair<LL, LL>> ppll;

vector<vector<ppl>> adjList;
vector<LL> dist;

void dijkstra(LL start) {
    priority_queue<ppll, vector<ppll>, greater<>> pq;
    dist.assign(adjList.size(), INF);
    dist[start] = 0;
    pq.push({dist[start], {start, 0}});

    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top(); pq.pop();
        if (curDist > dist[curNode.first]) continue;
        
        for (auto [neighbor, edgeWeight] : adjList[curNode.first]) {
            LL newDist = curDist + edgeWeight + adjList[neighbor][0].second;
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({dist[neighbor], {neighbor, edgeWeight}});
            }
        }
    }
}

void solve() {
    LL n, m;
    cin >> n >> m;
    
    adjList.resize(n + 1);
    for (LL i = 1; i <= n; ++i) {
        adjList[i].push_back({i, 0});
    }
    
    for (LL i = 1; i <= m; ++i) {
        LL u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    
    for (LL i = 2; i <= n; ++i) {
        dijkstra(i);
        cout << dist[1] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}