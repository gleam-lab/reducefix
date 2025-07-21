#include <bits/stdc++.h>
using namespace std;

#define INT long long
#define pb push_back

template <class T>
using V = vector<T>;

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1);
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    V<V<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    V<int> d(n + 1, INT_MAX);
    d[1] = a[1];

    // Priority queue to process nodes with the least path weight first
    priority_queue<pair<int, int>, V<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(d[1], 1);

    while (!pq.empty()) {
        auto [current_weight, u] = pq.top();
        pq.pop();
        if (current_weight > d[u]) continue;

        for (const auto &[v, weight] : g[u]) {
            int new_weight = current_weight + weight + a[v] - a[v]; // Calculate new weight
            if (new_weight < d[v]) {
                d[v] = new_weight;
                pq.emplace(d[v], v);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}