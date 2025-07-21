#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#include<climits>
using namespace std;

struct edge {
    int next, to;
} a[200001];
int n, m, head[200001], cnt, ans = INT_MAX;
int dist[200001];

inline int read() {
    int res = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

inline void add(const int u, const int v) {
    a[++cnt].next = head[u];
    a[cnt].to = v;
    head[u] = cnt;
}

void bfs() {
    queue<int> q;
    for(int i = 1; i <= n; ++i) dist[i] = -1;
    
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int i = head[u], v; i; i = a[i].next) {
            v = a[i].to;
            if(v == 1) {  // found a cycle back to node 1
                ans = min(ans, dist[u] + 1);
            }
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for(int i = 1, u, v; i <= m; ++i) {
        u = read(), v = read();
        add(u, v);
    }
    
    bfs();
    
    if(ans == INT_MAX) printf("-1");
    else printf("%d", ans);
    
    return 0;
}