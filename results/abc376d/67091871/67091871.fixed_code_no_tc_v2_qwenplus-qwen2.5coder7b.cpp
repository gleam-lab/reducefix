#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;
vector<int> b[MAXN];
bool vis[MAXN];

// Function to perform DFS and find the minimum cycle length
void dfs(int x, int parent, int& mn) {
    vis[x] = true;
    for (int v : b[x]) {
        if (!vis[v]) {
            dfs(v, x, mn);
        } else if (v != parent) { // Cycle detected
            mn = min(mn, abs(parent - v));
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
        b[v].push_back(u); // Assuming undirected graph
    }

    int mn = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, -1, mn); // -1 indicates no parent initially
        }
    }

    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn + 1; // Adding 1 to convert from zero-based index to one-based
    }
    return 0;
}