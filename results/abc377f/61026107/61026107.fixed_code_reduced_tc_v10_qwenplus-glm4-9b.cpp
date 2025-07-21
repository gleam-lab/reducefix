#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace dinic {
    struct Edge {
        int to;
        int cap;
        int rev;
    };
    
    const int maxn = 4e6 + 10;
    vector<Edge> G[maxn];
    int level[maxn];
    int iter[maxn];

    void clear(int n) {
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    
    bool bfs(int s, int t, int n) {
        fill(level, level + n, -1);
        queue<int> Q;
        Q.push(s);
        level[s] = 0;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (auto &e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    Q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }
    
    int dfs(int v, int t, int n, int f) {
        if (v == t) return f;
        int d = 0;
        for (auto &e : G[v]) {
            if (e.cap > 0 && level[v] < level[e.to]) {
                int df = dfs(e.to, t, n, min(e.cap, f - d));
                if (df > 0) {
                    e.cap -= df;
                    G[e.to][e.rev].cap += df;
                    d += df;
                    f -= df;
                    if (f == 0) break;
                }
            }
        }
        return d;
    }
    
    int max_flow(int s, int t, int n) {
        int flow = 0;
        while (bfs(s, t, n)) {
            fill(iter, iter + n, 0);
            flow += dfs(s, t, n, 1e9);
        }
        return flow;
    }
}

namespace ftw {
    const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int x(int r, int c, int n) {
        return r * n + c;
    }

    void add_edge(int &f, int &t, int cap, int n) {
        dinic::G[f].push_back({t, cap, dinic::x(f, t, n)});
        dinic::G[t].push_back({f, 0, dinic::x(t, f, n)});
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int s = dinic::x(n + 2, n + 2, n), t = dinic::x(n + 2, n + 3, n);
    
    for (int i = 1; i <= n; ++i) {
        ftw::add_edge(s, dinic::x(i, 1, n), 1, n);
        ftw::add_edge(dinic::x(i, n, n), t, 1, n);
    }
    
    set<pair<int, int>> positions;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        positions.emplace(y, x);
    }
    
    for (auto &p : positions) {
        for (int d = 0; d < 4; ++d) {
            int x = p.first + ftw::dx[d];
            int y = p.second + ftw::dy[d];
            if (1 <= x && x <= n && 1 <= y && y <= n) {
                int u = ftw::x(x, y, n);
                int v = ftw::x(y, x, n);
                ftw::add_edge(u, ftw::x(x, y + 1, n), 1, n);
                ftw::add_edge(v, ftw::x(y, x + 1, n), 1, n);
            }
        }
    }
    
    int ans = dinic::max_flow(s, t, n);
    cout << ans << '\n';
    return 0;
}