#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pii;
typedef vector<pii> vpi;
typedef priority_queue<pii, vpi, greater<pii>> min_heap;

long long dijkstra(int source, int dest, vector<vpi>& adjList, vector<long long>& weights) {
    int n = adjList.size();
    vector<long long> dist(n, LLONG_MAX);
    min_heap pq;
    
    dist[source] = weights[source];
    pq.push({dist[source], source});
    
    while (!pq.empty()) {
        auto [distance, node] = pq.top();
        pq.pop();
        
        if (node == dest)
            break;
        
        for (auto [neighbor, cost] : adjList[node]) {
            if (dist[node] + cost + weights[neighbor] < dist[neighbor]) {
                dist[neighbor] = dist[node] + cost + weights[neighbor];
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    
    return dist[dest];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<long long> weights(n+1);
    for(int i=1;i<=n;i++)
        cin >> weights[i];

    vector<vpi> adjList(n+1);
    for(int i=0;i<m;i++) {
        int u, v, b;
        cin >> u >> v >> b;
        adjList[u].push_back({v, b});
        adjList[v].push_back({u, b});
    }

    for(int i=2;i<=n;i++) {
        cout << dijkstra(1, i, adjList, weights) << " ";
    }
    
    return 0;
}