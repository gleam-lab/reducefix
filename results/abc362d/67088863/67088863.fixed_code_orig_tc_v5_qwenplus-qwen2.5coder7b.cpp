#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>

using namespace std;

const long long INF = 1e18;
int MOD = 1e9 + 7;
const int N = 2e5 + 5;

long long fpow(long long a, long long b, int m = MOD) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res % m;
}

long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> val(n);
    for (long long& i : val) cin >> i;

    vector<vector<pair<int, long long>>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        a--, b--; // Adjust indices to be zero-based
        adj[a].push_back({b, 1LL * w + val[a]});
        adj[b].push_back({a, 1LL * w + val[b]});
    }

    vector<long long> dist(n, INF);
    dist[0] = 0;
    vector<bool> vis(n, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        vis[v] = true;

        for (auto [u, ww] : adj[v]) {
            if (ww + dist[v] < dist[u]) {
                dist[u] = ww + dist[v];
                pq.push({dist[u], u});
            }
        }
    }

    for (int i = 1; i < n; i++)
        cout << dist[i] + val[i] << " ";

    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}