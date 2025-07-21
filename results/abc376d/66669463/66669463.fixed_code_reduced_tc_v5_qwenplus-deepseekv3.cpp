#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX_N = 200001;

vector<int> adj[MAX_N];
int dist[MAX_N];

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

    for (int v : adj[1]) {
        if (v == 1) {
            min_cycle = 1;
            continue;
        }

        fill(dist, dist + n + 1, -1);
        queue<int> q;
        q.push(v);
        dist[v] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int next : adj[u]) {
                if (next == 1) {
                    if (dist[u] + 1 < min_cycle) {
                        min_cycle = dist[u] + 1;
                    }
                    break;
                }
                if (dist[next] == -1) {
                    dist[next] = dist[u] + 1;
                    q.push(next);
                }
            }
            if (min_cycle == 2) break; // Early exit if the minimal possible cycle is found
        }
        if (min_cycle == 2) break; // Early exit if the minimal possible cycle is found
    }

    if (min_cycle != INT_MAX) {
        cout << min_cycle << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}