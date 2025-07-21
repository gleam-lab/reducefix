#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN];
int dist[MAXN];
int parent[MAXN];
int n, m;

int findShortestCycle() {
    int min_cycle = INT_MAX;
    
    for (int start = 1; start <= n; ++start) {
        queue<int> q;
        fill(dist, dist + n + 1, -1);
        fill(parent, parent + n + 1, -1);
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (parent[u] != v && parent[v] != u) {
                    min_cycle = min(min_cycle, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    
    return (min_cycle == INT_MAX) ? -1 : min_cycle;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int result = findShortestCycle();
    printf("%d\n", result);
    
    return 0;
}