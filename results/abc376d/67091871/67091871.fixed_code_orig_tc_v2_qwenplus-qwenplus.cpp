#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 200005;
vector<int> adj[MAX];
int dist[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Initialize distance array
    fill(dist, dist + n + 1, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    int min_cycle = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (v == 1 && dist[v] != 0) {
                // Found a cycle back to node 1
                int cycle_len = dist[u] + 1;
                if (min_cycle == -1 || cycle_len < min_cycle) {
                    min_cycle = cycle_len;
                }
            }
        }
    }

    cout << min_cycle << endl;

    return 0;
}