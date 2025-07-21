#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max() / 2; // Set to the maximum of long long to represent infinity

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u); // Since the graph is undirected, add edge in both directions
    }
    vector<int> dist(N, INF); // Representing the distance as infinity initially
    queue<pair<int, int>> que;
    que.push({0, 0});
    dist[0] = 0;
    while(!que.empty()) {
        int pos = que.front().first;
        int d = que.front().second;
        que.pop();
        for(int i = 0; i < G[pos].size(); i++) {
            int next = G[pos][i];
            if(dist[next] == INF) { // Check if the vertex has been visited
                que.push({next, d + 1});
                dist[next] = d + 1;
            }
        }
    }

    long long ans = INF; // Use long long to handle potentially large distances
    for(int i = 1; i < N; i++) {
        if(dist[i] != INF) { // Only consider vertices that are reachable
            ans = min(ans, dist[i]);
        }
    }

    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}