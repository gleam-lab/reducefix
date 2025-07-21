#include<bits/stdc++.h>
using namespace std;

template<typename T> bool chmax(T &m, const T q) {
    if (m < q) { m = q; return true; } else return false;
}

template<typename T> bool chmin(T &m, const T q) {
    if (m > q) { m = q; return true; } else return false;
}

#define rep(i, l, r) for (int i = (l); (r) > i; i++)
#define all(x) x.begin(), x.end()

using pqi = priority_queue<int>;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const long long INF = 1e18;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 10;

int main() {
    int N, M;
    cin >> N >> M;
    vvi G(N);
    vi dist(N, INF);
    dist[0] = 0; // Initialize the starting vertex distance to 0
    rep(i, 0, M) {
        int s, v;
        cin >> s >> v;
        s--; v--;
        G[s].pb(v);
    }
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        for (auto to : G[pos]) {
            if (dist[to] > dist[pos] + 1) { // Check if a shorter path is found
                dist[to] = dist[pos] + 1;
                que.push(to);
            }
        }
    }
    int minDist = *min_element(dist.begin(), dist.end());
    if (minDist == INF) {
        cout << -1 << endl;
    } else {
        cout << minDist << endl;
    }
}