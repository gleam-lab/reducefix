#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,ll>dist;

void bfs(ll start) {
    queue<ll> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        ll node = q.front();
        q.pop();

        for (ll neighbor : graph[node]) {
            if (dist[neighbor] == 0 || dist[neighbor] > dist[node] + 1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Ensure undirected graph
    }

    // Run BFS from node 1
    bfs(1);

    // Check the farthest node distance from node 1
    ll max_distance = 0;
    for (auto& p : dist) {
        if (p.first != 1 && p.second > max_distance) max_distance = p.second;
    }

    // Output the result
    if (max_distance == 0) cout << "0" << endl;
    else cout << max_distance - 1 << endl;

    return 0;
}