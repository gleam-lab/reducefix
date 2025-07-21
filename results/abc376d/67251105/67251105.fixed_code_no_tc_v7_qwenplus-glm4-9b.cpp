#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2005;
const int INF = 1e9;

int n, m;
vector<int> graph[MAXN];
int dist[MAXN];

bool bfs() {
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return dist[n - 1] != -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (!bfs()) {
        cout << "-1" << endl;
        return 0;
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        bool hasEdgeToZero = false;
        for (int neighbor : graph[i]) {
            if (neighbor == 0) {
                hasEdgeToZero = true;
                break;
            }
        }
        if (hasEdgeToZero) {
            ans = min(ans, dist[i]);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans + 1 << endl;
    }

    return 0;
}