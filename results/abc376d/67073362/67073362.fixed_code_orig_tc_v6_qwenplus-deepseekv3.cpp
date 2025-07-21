#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int INF = INT_MAX;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int min_cycle = INF;
    queue<pair<int, int>> q; // node, distance from node 1
    vector<int> dist(n + 1, -1);
    q.push({1, 0});
    dist[1] = 0;

    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (v == 1) {
                if (d + 1 < min_cycle) {
                    min_cycle = d + 1;
                }
            }
            if (dist[v] == -1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }

    if (min_cycle == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}