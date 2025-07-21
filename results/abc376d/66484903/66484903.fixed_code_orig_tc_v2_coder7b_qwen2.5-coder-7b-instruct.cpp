#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
queue<int> q;
int step[MAXN], vis[MAXN];

int bfs(int start, int target) {
    memset(vis, 0, sizeof(vis));
    memset(step, 0, sizeof(step));
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (auto neighbor : adj[top]) {
            if (!vis[neighbor]) {
                step[neighbor] = step[top] + 1;
                vis[neighbor] = true;
                q.push(neighbor);

                if (neighbor == target) {
                    return step[neighbor];
                }
            }
        }
    }

    return -1;
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    int result = bfs(1, n);
    printf("%d\n", result);

    return 0;
}