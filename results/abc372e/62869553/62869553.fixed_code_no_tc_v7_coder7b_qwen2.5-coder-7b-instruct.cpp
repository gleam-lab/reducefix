#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

vector<int> adj[MAXN];
int degree[MAXN];

void dfs(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        degree[u] += degree[v];
        if (degree[u] > MAXK) return; // Early termination if the degree exceeds MAXK
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            if (degree[v] < k) {
                cout << -1 << '\n';
            } else {
                vector<int> temp;
                for (auto u : adj[v]) {
                    temp.push_back(u);
                }
                sort(temp.begin(), temp.end());
                cout << temp[k - 1] << '\n';
            }
        }
    }

    return 0;
}