#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n+1);
    for(int i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    ll min_cycle = LLONG_MAX;
    queue<pair<ll, ll>> q;
    vector<ll> dist(n+1, -1);
    vector<ll> parent(n+1, -1);

    q.push({1, 0});
    dist[1] = 0;

    while(!q.empty()) {
        auto [current, d] = q.front();
        q.pop();

        for(auto neighbor : graph[current]) {
            if(neighbor == 1 && d >= 1) {
                min_cycle = min(min_cycle, d + 1);
                continue;
            }
            if(dist[neighbor] == -1) {
                dist[neighbor] = d + 1;
                parent[neighbor] = current;
                q.push({neighbor, d + 1});
            }
        }
    }

    if(min_cycle != LLONG_MAX) {
        cout << min_cycle << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}