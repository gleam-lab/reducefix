#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200001;
vector<int> graph[N];
int dist[N], n, m;
int ans = 100000000;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    fill(dist, dist + n + 1, -1);
    bfs(1);
    
    if (dist[1] == -1) {
        printf("-1");
    } else {
        printf("%d", dist[1]);
    }
    
    return 0;
}