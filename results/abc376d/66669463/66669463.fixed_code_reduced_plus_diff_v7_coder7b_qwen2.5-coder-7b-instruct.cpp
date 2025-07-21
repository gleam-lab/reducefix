#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
bool visited[MAXN];

void bfs(int start, vector<int>& distances) {
    fill(distances.begin(), distances.end(), INT_MAX);
    queue<int> q;
    q.push(start);
    distances[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v : adj[u]) {
            if (distances[v] == INT_MAX) {
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1);
    bfs(1, dist);

    int ans = *max_element(dist.begin() + 2, dist.begin() + n + 1);
    if (ans == INT_MAX) cout << "-1" << endl;
    else cout << ans << endl;

    return 0;
}