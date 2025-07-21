#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int MAXN = 2e5 + 10;

vector<int> adj[MAXN];
int inStack[MAXN], visited[MAXN], dist[MAXN];
int ans = -1;

void dfs(int node, int depth, vector<int>& path, map<int, int>& pos) {
    if (visited[node]) {
        if (inStack[node]) {
            int cycleStart = pos[node];
            int cycleLength = depth - cycleStart;
            if (ans == -1 || cycleLength < ans)
                ans = cycleLength;
        }
        return;
    }

    visited[node] = 1;
    inStack[node] = 1;
    path.push_back(node);
    pos[node] = depth;

    for (int nei : adj[node]) {
        if (!visited[nei]) {
            dfs(nei, depth + 1, path, pos);
            if (ans != -1) return; // Early exit if shortest cycle already found
        } else {
            dfs(nei, depth + 1, path, pos);
            if (ans != -1) return;
        }
    }

    path.pop_back();
    pos.erase(node);
    inStack[node] = 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> path;
    map<int, int> pos;
    memset(visited, 0, sizeof(visited));
    memset(inStack, 0, sizeof(inStack));

    dfs(1, 0, path, pos);

    cout << (ans == -1 ? -1 : ans) << endl;
}

signed main() {
    IOS;
    solve();
    return 0;
}