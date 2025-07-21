#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

ll findShortestCycle(map<ll, vector<ll>>& graph, ll n) {
    ll min_cycle = INF;
    
    for (auto& [u, neighbors] : graph) {
        if (u == 1) continue; // We'll handle node 1 separately
        
        map<ll, ll> distance;
        distance[u] = 0;
        queue<ll> q;
        q.push(u);
        
        while (!q.empty()) {
            ll current = q.front();
            q.pop();
            
            for (ll v : graph[current]) {
                if (v == 1) {
                    if (distance[current] + 1 < min_cycle) {
                        min_cycle = distance[current] + 1;
                    }
                }
                if (distance.find(v) == distance.end()) {
                    distance[v] = distance[current] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    return min_cycle;
}

int main() {
    ll n, m;
    cin >> n >> m;
    
    map<ll, vector<ll>> graph;
    
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    // First check direct edges from 1 back to 1
    for (ll v : graph[1]) {
        if (v == 1) {
            cout << 1 << endl;
            return 0;
        }
    }
    
    ll shortest_cycle = findShortestCycle(graph, n);
    
    if (shortest_cycle != INF) {
        cout << shortest_cycle << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}