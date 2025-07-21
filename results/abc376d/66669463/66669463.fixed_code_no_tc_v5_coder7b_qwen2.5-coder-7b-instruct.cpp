#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[200001];

int n, m, dist[200001];

inline int read() {
    int res = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

void bfs() {
    queue<int> q;
    for(int i = 1; i <= n; ++i) dist[i] = -1;
    dist[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto &v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if(dist[1] != -1) printf("%d\n", dist[1]);
    else printf("-1\n");
}

int main() {
    n = read(); m = read();
    for(int i = 1, u, v; i <= m; ++i) {
        u = read(); v = read();
        adj[u].push_back(v);
    }

    bfs();

    return 0;
}