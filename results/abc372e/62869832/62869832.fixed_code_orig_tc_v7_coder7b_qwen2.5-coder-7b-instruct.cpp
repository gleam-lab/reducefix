#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];

void dfs(int node, vector<bool>& visited, vector<int>& degree) {
    visited[node] = true;
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            degree[neighbor]++;
            dfs(neighbor, visited, degree);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if (type == 2) {
            cin >> u >> k;
            vector<int> neighbors;
            for (auto neighbor : adj[u]) {
                neighbors.push_back(neighbor);
            }
            sort(neighbors.begin(), neighbors.end());
            if (neighbors.size() < k) {
                cout << "-1" << endl;
            } else {
                cout << neighbors[k - 1] << endl;
            }
        }
    }

    return 0;
}