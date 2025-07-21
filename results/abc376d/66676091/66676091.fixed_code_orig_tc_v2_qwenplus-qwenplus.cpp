#include <bits/stdc++.h>
using namespace std;

template<typename T> bool chmax(T &m, const T q) {
    if (m < q) { m = q; return true; } else return false;
}

template<typename T> bool chmin(T &m, const T q) {
    if (m > q) { m = q; return true; } else return false;
}

#define rep(i,l,r) for(int i=(l); (i)<(r); ++i)
#define rrep(i,l,r) for(int i=(r)-1; (i)>=(l); --i)
#define all(x) x.begin(), x.end()
#define el '\n'
#define spa ' '
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define cou(i) cout << i << el
#define pb push_back

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vb = vector<bool>;

const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;
    vvi G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
    }

    // BFS from node 0 to detect cycles back to 0
    vi dist(N, INF);
    vb visited(N, false);
    queue<int> que;
    dist[0] = 0;
    visited[0] = true;
    que.push(0);

    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : G[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                que.push(v);
            } else if (v == 0) {
                // If we come back to node 0, update the shortest cycle length
                chmin(dist[u] + 1, dist[0]);
            }
        }
    }

    int min_cycle = INF;
    rep(u, 0, N) {
        if (dist[u] != INF) {
            for (int v : G[u]) {
                if (v == 0 && dist[u] != INF) {
                    chmin(min_cycle, dist[u] + 1);
                }
            }
        }
    }

    if (min_cycle == INF) {
        cout << -1 << el;
    } else {
        cout << min_cycle << el;
    }

    return 0;
}