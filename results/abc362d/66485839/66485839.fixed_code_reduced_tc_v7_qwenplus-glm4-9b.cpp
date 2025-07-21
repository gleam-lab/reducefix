#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int N = 200010;
const long long INF = numeric_limits<long long>::max();

vector<pair<int, int>> g[N];
long long d[N];

void solve() {
    int n, m;
    cin >> n >> m;
    long long a[N];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(-a[1], 1); // Use negative because priority_queue is max heap by default
    d[1] = 0; // Distance to itself is zero

    while (!pq.empty()) {
        auto [wt, pos] = pq.top();
        pq.pop();
        if (d[pos] != -wt) continue; // If already visited
        d[pos] = -wt;
        for (auto &edge : g[pos]) {
            int next = edge.first;
            long long nextWt = edge.second;
            if (d[next] > -wt + a[next] + nextWt) {
                d[next] = -wt + a[next] + nextWt;
                pq.emplace(-d[next], next);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i < n ? " " : "");
    }
}

int main() {
    solve();
    return 0;
}