#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) for (ll i=0; i<(ll)(n); ++i)
#define rep2(i,n) for (ll i=0; i<(ll)(n); ++i)
#define rep3(i,a,b) for (ll i=(ll)(a); i<(ll)(b); ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME

typedef long long ll;
constexpr ll INF = 5LL << 60;

template <typename T>
void chmin(T &x, const T &y) { if (y < x) x = y; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vec<ll> A(n);
    rep(n) cin >> A[i];

    vec<vec<pair<ll, ll>>> graph(n);
    rep(m) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    vec<ll> dist(n, INF);
    dist[0] = A[0]; // Start node's initial cost includes its own weight

    using P = pair<ll, ll>; // (total cost, node)
    priority_queue<P, vec<P>, greater<P>> pq;
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_cost = cost + b + A[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(new_cost, v);
            }
        }
    }

    rep(i, 1, n) {
        cout << dist[i];
        if (i != n - 1) cout << " ";
        else cout << "\n";
    }

    return 0;
}