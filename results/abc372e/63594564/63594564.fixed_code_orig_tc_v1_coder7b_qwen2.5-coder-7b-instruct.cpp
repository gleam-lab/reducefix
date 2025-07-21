#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()
const int N = 2e5 + 5;

vector<int> adj[N];
vector<vector<int>> pq(N);

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent) {
    pq[node].push_back(node);
    for (auto child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            for (auto val : pq[child])
                pq[node].push_back(val);
        }
    }
    sort(pq[node].begin(), pq[node].end());
    while (pq[node].size() > 10)
        pq[node].pop_back();
}

int getKthLargest(int node, int k) {
    if (k > pq[node].size())
        return -1;
    return pq[node][k - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    dfs(1, -1);

    while (q--) {
        int type, u, k;
        cin >> type >> u >> k;
        if (type == 1)
            addEdge(u, v);
        else
            cout << getKthLargest(u, k) << '\n';
    }

    return 0;
}