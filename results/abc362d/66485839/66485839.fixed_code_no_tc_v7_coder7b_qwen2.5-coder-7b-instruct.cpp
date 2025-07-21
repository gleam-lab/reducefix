#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pbk push_back
#define LL long long
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define INF 1e18
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void unionSet(int node1, int node2) {
        int p1 = find(node1), p2 = find(node2);
        if (p1 != p2) {
            if (rank[p1] > rank[p2])
                parent[p2] = p1;
            else if (rank[p2] > rank[p1])
                parent[p1] = p2;
            else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }
};

struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& e) const { return weight < e.weight; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    vector<ll> ans(n + 1, INF);
    ans[1] = a[1];
    
    for (auto& e : edges) {
        int p1 = dsu.find(e.src), p2 = dsu.find(e.dest);
        if (p1 != p2) {
            dsu.unionSet(p1, p2);
            ans[e.dest] = min(ans[e.dest], ans[e.src] + e.weight + a[e.dest]);
            ans[e.src] = min(ans[e.src], ans[e.dest] + e.weight + a[e.src]);
        }
    }

    for (int i = 2; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
        solve();
    return 0;
}