#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;

int n, m, mn = INT_MAX;
bool vis[MAXN];
vector<int> b[MAXN];

void dfs(int x, int cnt) {
    if (vis[x]) return;
    vis[x] = true;
    int ans = cnt + 1;
    for (int i = 0; i < b[x].size(); ++i) {
        int next = b[x][i];
        if (!vis[next] || next == 1) {
            if (next == 1) {
                mn = min(mn, ans);
            } else {
                dfs(next, ans);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
        b[v].push_back(u); // Assuming undirected graph
    }
    dfs(1, 0);
    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}