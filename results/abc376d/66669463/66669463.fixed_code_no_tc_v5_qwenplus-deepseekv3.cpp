#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

const int MAXN = 200001;
const int INF = 1e9;

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

int find_min_cycle() {
    fill(dist, dist + n + 1, INF);
    queue<int> q;
    
    for (int v : adj[1]) {
        dist[v] = 1;
        q.push(v);
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1) {
                return dist[u] + 1;
            }
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return -1;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        adj[u].push_back(v);
    }
    
    int result = find_min_cycle();
    printf("%d", result);
    
    return 0;
}