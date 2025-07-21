#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 2 * 100001;

vector<int> adj[MAXN];
bool visited[MAXN];
int distance[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
}

int minCycleLength(vector<vector<int>>& edges, int n) {
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
    }

    bfs(1);

    for (int i = 1; i <= n; ++i) {
        if (distance[i] != INT_MAX && i == 1) {
            return distance[i];
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int result = minCycleLength(edges, n);
    cout << result << endl;

    return 0;
}