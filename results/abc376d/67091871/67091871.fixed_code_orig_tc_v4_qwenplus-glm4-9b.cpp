#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, mn = 200005, vis[200005];
vector<int> b[200005];

void dfs(int x, int cnt) {
    vis[x] = 1;
    for (int i = 0; i < b[x].size(); i++) {
        if (!vis[b[x][i]]) {
            dfs(b[x][i], cnt + 1);
        }
        // Check if we found node 1 as a child and update mn
        if (b[x][i] == 1 && cnt + 1 < mn) {
            mn = cnt + 1;
        }
    }
    vis[x] = 0; // Reset the visited flag after recursion
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    dfs(1, 0);
    if (mn == 200005) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}