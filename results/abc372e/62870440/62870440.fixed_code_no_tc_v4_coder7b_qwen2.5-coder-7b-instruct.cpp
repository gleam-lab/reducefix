#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

vector<int> adj[MAXN];
int sz[MAXN], parent[MAXN], depth[MAXN];

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;
    sz[node] = 1;
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
            sz[node] += sz[child];
        }
    }
}

int getKthLargest(int node, int k) {
    vector<int> temp;
    function<void(int)> traverse = [&](int v) {
        if (v == node) return;
        for (int u : adj[v]) {
            traverse(u);
            temp.push_back(u);
        }
    };
    traverse(node);
    sort(temp.begin(), temp.end());
    if (temp.size() < k) return -1;
    return temp[temp.size() - k];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            cout << getKthLargest(v, k) << '\n';
        }
    }

    return 0;
}