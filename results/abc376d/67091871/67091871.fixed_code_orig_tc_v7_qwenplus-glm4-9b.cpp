#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, mn = 200005, vis[200005];
vector<int> b[200005];
bool visited[200005];

void dfs(int x, int cnt) {
    vis[x] = 1;
    ll ans = cnt + 1;
    for (int i = 0; i < b[x].size(); i++) {
        if (!vis[b[x][i]] || b[x][i] == 1) {
            if (b[x][i] == 1) {
                mn = min(mn, ans);
            } else {
                dfs(b[x][i], ans);
            }
        }
    }
    vis[x] = 0; // Reset visited status to allow revisiting in other components
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    memset(visited, 0, sizeof(visited)); // Initialize visited array
    dfs(1, 0);
    if (mn == 200005) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}