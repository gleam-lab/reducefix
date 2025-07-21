#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct DSU {
    vector<ll> parent, rank;
    DSU(ll n) : parent(n+1), rank(n+1, 1) {
        for (ll i = 0; i <= n; ++i) parent[i] = i;
    }
    ll find(ll x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(ll x, ll y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        return true;
    }
};

struct Edge {
    ll u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    
    vector<ll> a(n+1);
    for (ll i = 1; i <= n; ++i) cin >> a[i];

    vector<Edge> edges(m);
    for (ll i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({a[1], 1});

    vector<ll> ans(n, LLONG_MAX);
    ans[1] = 0;

    for (auto &edge : edges) {
        ll pu = dsu.find(edge.u), pv = dsu.find(edge.v);
        if (pu == pv) continue;
        dsu.unite(pu, pv);
        
        while (!pq.empty() && pq.top().second == pu) {
            ll dist = pq.top().first;
            pq.pop();
            
            if (dist + edge.w + a[pv] < ans[pv]) {
                ans[pv] = dist + edge.w + a[pv];
                pq.push({ans[pv], pv});
            }
        }
        
        if (ans[pu] != LLONG_MAX && ans[pu] + edge.w + a[pv] < ans[pv]) {
            ans[pv] = ans[pu] + edge.w + a[pv];
            pq.push({ans[pv], pv});
        }
    }

    for (ll i = 2; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}