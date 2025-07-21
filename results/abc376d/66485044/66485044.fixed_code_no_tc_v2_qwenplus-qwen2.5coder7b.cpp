#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
queue<int> q;
int dist[MAXN];
bool visited[MAXN];

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }
    q.push(1);
    dist[1] = 0;
    visited[1] = true;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int neighbor : adj[top]) {
            if (!visited[neighbor]) {
                dist[neighbor] = dist[top] + 1;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    if (dist[n] != INF) {
        printf("%d\n", dist[n]);
    } else {
        printf("-1\n");
    }
    return 0;
}