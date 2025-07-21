#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<ll> a(n); for (ll i = 0; i < n; ++i) cin >> a[i];

    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b; cin >> u >> v >> b;
        --u; --v;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    vector<ll> costs(n-1, LLONG_MAX);
    set<ll> rest_nodes; for (ll i = 0; i < n; ++i) rest_nodes.insert(i);

    auto cmp = [&](const tuple<ll, ll, ll>& x, const tuple<ll, ll, ll>& y) {
        return a[get<0>(x)] + get<1>(x) + get<2>(x) > a[get<0>(y)] + get<1>(y) + get<2>(y);
    };
    
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, decltype(cmp)> heap(cmp);
    heap.emplace(0, 0, a[0]);

    while (!rest_nodes.empty()) {
        auto [current_node, current_edge, current_cost] = heap.top(); heap.pop();

        if (!rest_nodes.count(current_node)) continue;
        rest_nodes.erase(current_node);
        if (current_node != 0) costs[current_node-1] = current_cost;

        for (auto [node, weight]: graph[current_node]) {
            if (rest_nodes.count(node)) {
                heap.emplace(node, weight, current_cost + a[node] + weight);
            }
        }
    }

    for (ll cost : costs) {
        cout << cost << ' ';
    }
    cout << '\n';

    return 0;
}