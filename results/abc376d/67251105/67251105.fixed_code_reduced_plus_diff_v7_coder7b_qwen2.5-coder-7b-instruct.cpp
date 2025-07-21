#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    
    // Initialize distance array with infinity
    vector<int> dist(N, INF);
    dist[0] = 0;
    
    // Priority queue to process nodes by their distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int pos = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[pos]) continue;
        
        for (int i = 0; i < G[pos].size(); i++) {
            int nex = G[pos][i];
            if (dist[nex] <= d + 1) continue;
            dist[nex] = d + 1;
            pq.push({dist[nex], nex});
        }
    }
    
    // Check if there is a path from node 0 to any other node
    bool hasPath = false;
    for (int i = 1; i < N; i++) {
        if (dist[i] != INF) {
            hasPath = true;
            break;
        }
    }
    
    if (hasPath) {
        cout << *min_element(begin(dist), end(dist)) + 1 << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}