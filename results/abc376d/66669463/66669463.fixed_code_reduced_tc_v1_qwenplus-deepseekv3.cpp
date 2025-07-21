#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN];
int dist[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int min_cycle = INT_MAX;

    for (int neighbor : adj[1]) {
        if (neighbor == 1) {
            min_cycle = 1;
            break;
        }
    }

    if (min_cycle != 1) {
        for (int neighbor : adj[1]) {
            queue<int> q;
            fill(dist, dist + n + 1, -1);
            dist[neighbor] = 1;
            q.push(neighbor);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (v == 1) {
                        if (min_cycle > dist[u] + 1) {
                            min_cycle = dist[u] + 1;
                        }
                        break;
                    }
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
                if (min_cycle == 2) break; // Early exit if cycle of length 2 found
            }
            if (min_cycle == 2) break; // Early exit if cycle of length 2 found
        }
    }

    if (min_cycle == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << min_cycle << "\n";
    }

    return 0;
}