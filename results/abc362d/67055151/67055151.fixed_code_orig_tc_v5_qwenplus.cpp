#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <locale>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <sys/types.h>
#include <system_error>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <valarray>
#include <vector>
#include <cmath>
#include <concepts>
#include <type_traits>

#define vec vector

// マクロオーバーロード用のヘルパー
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME

#define REP1(n) for (ll i=0; i<(ll)(n); i++)
#define REP2(i, n) for (ll i=0; i<(ll)(n); i++)
#define REP3(i, begin, end) for (ll i=(ll)(begin); i<(ll)(end); i++)
#define rep(...) GET_MACRO(__VA_ARGS__, REP3, REP2, REP1)(__VA_ARGS__)

#define RREP1(n) for (ll i=(ll)(n)-1; i>=0; i--)
#define RREP2(i, n) for (ll i=(ll)(n)-1; i>=0; i--)
#define RREP3(i, begin, end) for (ll i=(ll)(end)-1; i>=(ll)(begin); i--)
#define rrep(...) GET_MACRO(__VA_ARGS__, RREP3, RREP2, RREP1)(__VA_ARGS__)

#define drep(i, j, ibegin, iend, jbegin, jend) \
	rep(i, ibegin, iend) rep(j, jbegin, jend)

#define trep(i, j, k, ibegin, iend, jbegin, jend, kbegin, kend) \
	rep(i, ibegin, iend) rep(j, jbegin, jend) rep(k, kbegin, kend)

#define arep(elm, iter) for (auto&& elm: iter)

// ==================================================

// 定数とかの宣言

using namespace std;

constexpr char el = '\n';

using ll = long long;
const ll INF = 5LL << 60;

template <typename T>
void chmin(T& x, const T& y) { x = min(x, y); }

template <typename T>
void chmax(T& x, const T& y) { x = max(x, y); }

// ==================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; 
    cin >> n >> m;
    vec<ll> a(n); 
    rep(n) cin >> a[i];

    vec<vec<pair<ll, ll>>> graph(n);
    rep(m) {
        ll ui, vi, bi; 
        cin >> ui >> vi >> bi;
        ui--; vi--;
        graph[ui].push_back({vi, bi});
        graph[vi].push_back({ui, bi});
    }

    // Dijkstra's algorithm
    vec<ll> dist(n, INF);
    priority_queue<pair<ll, ll>, vec<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    
    // Start from vertex 0 (vertex 1 in 1-indexed)
    dist[0] = a[0];  // Only include starting vertex weight
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            ll new_dist = dist[u] + w + a[v];  // current distance + edge weight + destination vertex weight
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    // Output results for vertices 2 to N (1-indexed), which are indices 1 to n-1 (0-indexed)
    for (ll i = 1; i < n; i++) {
        cout << dist[i];
        if (i < n - 1) cout << " ";
    }
    cout << el;

    return 0;
}