#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, vector<ll>> graph;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    ll ans = -1;
    queue<pair<ll, ll>> q;
    q.push({1, 0});

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        ll node = current.first;
        ll dist = current.second;

        for (auto neighbor : graph[node]) {
            if (neighbor == 1) {
                if (dist + 1 < ans || ans == -1) {
                    ans = dist + 1;
                }
                continue;
            }
            if (dist + 1 >= ans && ans != -1) continue;
            q.push({neighbor, dist + 1});
        }
    }

    cout << ans << endl;
    return 0;
}