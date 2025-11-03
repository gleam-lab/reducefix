#include <algorithm>
#include <cassert>
#include <cctype>
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

using namespace std;

constexpr char el = '\n';

using ll = long long;
const ll INF = 5LL << 60;

template <typename T>
void chmin(T& x, const T& y) { x = min(x, y); }

template <typename T>
void chmax(T& x, const T& y) { x = max(x, y); }

template <typename... Args>
void out(const Args&... args) {
    ((cout << args << " "), ...);
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vec<ll> a(n);
    rep(n) cin >> a[i];

    vec<vec<pair<ll, ll>>> graph(n);
    rep(m) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    // Dijkstra's algorithm
    vec<ll> dist(n, INF);
    dist[0] = a[0]; // Start vertex weight is included

    priority_queue<pair<ll, ll>, vec<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            ll new_cost = dist[u] + w + a[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }

    // Output results for vertices 2 to N (1-indexed)
    rep(i, 1, n) {
        cout << dist[i];
        if (i < n - 1) cout << " ";
    }
    cout << el;

    return 0;
}