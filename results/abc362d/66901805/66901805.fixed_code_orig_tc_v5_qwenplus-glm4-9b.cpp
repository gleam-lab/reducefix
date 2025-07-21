#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
vector<pair<int, int>> adj[200005];

int n, m, a[200005], ans[200005], depth[200005];
int parent[200005], rank[200005];

// Find function for universe
int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

// Union function for universe
void union_set(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, b;
        scanf("%lld %lld %lld", &u, &v, &b);
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    // Initialize
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Diagonal edges for each vertex
    for (int i = 1; i <= n; ++i) {
        adj[i].push_back({i, a[i]});
    }

    // Start from the first vertex
    parent[1] = 1;
    ans[1] = a[1];

    for (int i = 2; i <= n; ++i) {
        ans[i] = INF;
        parent[i] = 1;
    }

    // Set for tracking visited nodes
    set<int> visited;

    for (int i = 1; i <= n; ++i) {
        if (visited.count(find(i))) continue;
        visited.insert(find(i));
        queue<int> q;
        q.push(i);
        depth[i] = -a[i]; // Use negative values for vertex weights
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto e : adj[u]) {
                int v = e.first;
                int b = e.second;
                int pu = find(u);
                int pv = find(v);
                if (pu != pv) {
                    union_set(u, v);
                    int dp = depth[u] + depth[v] + b;
                    if (dp < ans[v]) {
                        ans[v] = dp;
                    }
                    q.push(v);
                    depth[v] = dp - b;
                }
            }
        }
    }

    // Output answers for vertices 2 to N
    for (int i = 2; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}