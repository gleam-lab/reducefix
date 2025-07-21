#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

const int N = 2e5 + 5;

vector<int> adj[N];
vector<int> degree(N, 0);
vector<int> result[N];

bool visited[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dfs(int node) {
    visited[node] = true;
    for(auto child : adj[node]) {
        if(!visited[child]) {
            dfs(child);
            result[node].insert(result[node].end(), result[child].begin(), result[child].end());
        }
    }
    result[node].push_back(node);
    sort(result[node].begin(), result[node].end(), greater<int>());
    if(result[node].size() > 10) {
        result[node].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        result[i].clear();
    }
    memset(degree, 0, sizeof(degree));
    memset(visited, false, sizeof(visited));

    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        } else {
            if(degree[u] == 0 || degree[v] == 0) {
                cout << -1 << '\n';
                continue;
            }
            int posu = lower_bound(result[u].begin(), result[u].end(), v) - result[u].begin();
            int posv = lower_bound(result[v].begin(), result[v].end(), u) - result[v].begin();

            if(posu >= 10 || posv >= 10) {
                cout << -1 << '\n';
            } else {
                cout << min(result[u][posu], result[v][posv]) << '\n';
            }
        }
    }

    return 0;
}