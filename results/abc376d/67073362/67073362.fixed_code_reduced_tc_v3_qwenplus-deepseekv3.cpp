#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int dist[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    fill(dist, dist + n + 1, INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    int min_cycle = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (min_cycle == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}