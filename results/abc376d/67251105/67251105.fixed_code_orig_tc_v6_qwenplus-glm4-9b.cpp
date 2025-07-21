#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Assuming 0-indexed
        G[u].push_back(v);
        G[v].push_back(u); // Assuming undirected graph
    }

    vector<int> dist(N, INF);
    queue<int> que;
    que.push(0);
    dist[0] = 0;

    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int v : G[u]) {
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < N; ++i) {
        bool is_leaf = true;
        for(int v : G[i]) {
            if(dist[v] < dist[i]) // If there is an edge from i with a smaller distance
                is_leaf = false;
        }
        if(is_leaf) {
            ans = min(ans, dist[i]);
        }
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}