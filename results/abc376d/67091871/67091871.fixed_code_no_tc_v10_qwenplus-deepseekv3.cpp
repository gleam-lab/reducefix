#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = 200005;
vector<int> b[200005];

void bfs() {
    queue<pair<int, int>> q;
    vector<int> dist(n + 1, -1);
    q.push({1, 0});
    dist[1] = 0;

    while (!q.empty()) {
        auto [current, cnt] = q.front();
        q.pop();

        for (int neighbor : b[current]) {
            if (neighbor == 1) {
                mn = min(mn, cnt + 1);
                continue;
            }
            if (dist[neighbor] == -1 || cnt + 1 < dist[neighbor]) {
                dist[neighbor] = cnt + 1;
                q.push({neighbor, cnt + 1});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }

    bfs();

    if (mn == 200005) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}