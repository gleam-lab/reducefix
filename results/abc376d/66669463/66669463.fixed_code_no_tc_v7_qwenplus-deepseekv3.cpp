#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 200001;
const int INF = 100000000;

vector<int> adj[MAXN];
int dist[MAXN];
int n, m;

inline int read() {
    int res = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        res = (res << 1) + (res << 3) + (c ^ 48);
        c = getchar();
    }
    return res;
}

int findShortestCycle() {
    int min_cycle = INF;
    
    for (int u = 1; u <= n; ++u) {
        fill(dist, dist + n + 1, -1);
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int neighbor : adj[v]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[v] + 1;
                    q.push(neighbor);
                } else if (neighbor == u) {
                    min_cycle = min(min_cycle, dist[v] + 1);
                }
            }
        }
    }
    
    return min_cycle == INF ? -1 : min_cycle;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        adj[u].push_back(v);
    }
    
    int result = findShortestCycle();
    printf("%d", result);
    
    return 0;
}