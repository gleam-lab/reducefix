#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int mx = 2e5 + 5;

vector<int> adj[mx];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq[mx];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int par, vector<int>& dist) {
    dist[node] = 1;
    for(auto child : adj[node]) {
        if(child != par) {
            dfs(child, node, dist);
            dist[node] += dist[child];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        pq[i].push({INT_MAX, i});
    }

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            if(k > pq[v].size()) cout << "-1" << endl;
            else {
                auto it = pq[v].nth_element(pq[v].begin(), pq[v].begin() + k - 1, pq[v].end());
                cout << (*it).second << endl;
            }
        }
    }

    return 0;
}