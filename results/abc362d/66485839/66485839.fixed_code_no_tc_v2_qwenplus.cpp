#include <bits/stdc++.h>
using namespace std;
#define INT signed
#define pbk push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;

struct Node {
    int x;
    long long w;
    bool operator < (const Node& u) const {
        return w > u.w; // Min-heap: smaller weight has higher priority
    }
};

constexpr int MAX_N = 200010;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, i64>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        i64 c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    
    vector<i64> dist(n + 1, LLONG_MAX);
    vector<bool> visited(n + 1, false);
    
    priority_queue<Node> pq;
    dist[1] = a[1]; // Starting at vertex 1, we pay its vertex weight
    pq.push({1, dist[1]});
    
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, edge_weight] : g[u]) {
            i64 new_dist = dist[u] + edge_weight + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i];
        if (i < n) cout << ' ';
        else cout << '\n';
    }
    
    return 0;
}