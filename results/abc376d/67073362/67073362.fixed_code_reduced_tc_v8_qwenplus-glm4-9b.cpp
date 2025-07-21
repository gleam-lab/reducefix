#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long

using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int visited[N];
int dist[N];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    dist[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neight : adj[curr]) {
            if (!visited[neight]) {
                visited[neight] = 1;
                dist[neight] = dist[curr] + 1;
                q.push(neight);
            }
        }
    }
}

int solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS from node 1
    bfs(1);

    // Find the farthest node from node 1
    int farthestNode = 1;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > dist[farthestNode]) {
            farthestNode = i;
        }
    }

    // BFS from the farthest node found
    bfs(farthestNode);

    // Find the farthest node from the farthest node found
    int furthestNode = farthestNode;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > dist[furthestNode]) {
            furthestNode = i;
        }
    }

    cout << dist[furthestNode] << endl;
    return 0;
}

int main() {
    ios;
    solve();
    return 0;
}