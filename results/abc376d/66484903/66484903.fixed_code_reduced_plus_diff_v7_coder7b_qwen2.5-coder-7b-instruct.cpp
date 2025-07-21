#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
queue<int> q;
int step[MAXN];
bool vis[MAXN];

void bfs(int start) {
    q.push(start);
    vis[start] = true;
    step[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                step[v] = step[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    bfs(1);

    for (int i = 2; i <= n; i++) {
        cout << step[i] << " ";
    }
    cout << endl;

    return 0;
}