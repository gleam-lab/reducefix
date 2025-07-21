#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAXN = 200001;

vector<int> adj[MAXN];
int dist[MAXN];
int parent[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    int min_cycle = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (v == 1) {
                if (dist[u] + 1 < min_cycle) {
                    min_cycle = dist[u] + 1;
                }
            }
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (min_cycle != INT_MAX) {
        cout << min_cycle << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}