#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj[MAX_N];
priority_queue<int, vector<int>, greater<int>> pq[MAX_N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
    if (pq[u].size() > 10) pq[u].pop();
    if (pq[v].size() > 10) pq[v].pop();
}

void removeEdge(int u, int v) {
    auto it = find(adj[u].begin(), adj[u].end(), v);
    if (it != adj[u].end()) {
        adj[u].erase(it);
        pq[u].erase(find(pq[u].begin(), pq[u].end(), v));
        if (pq[u].empty()) pq[u].push(-1);
    }
    it = find(adj[v].begin(), adj[v].end(), u);
    if (it != adj[v].end()) {
        adj[v].erase(it);
        pq[v].erase(find(pq[v].begin(), pq[v].end(), u));
        if (pq[v].empty()) pq[v].push(-1);
    }
}

int getKthLargest(int u, int k) {
    if (k > pq[u].size()) return -1;
    return pq[u].top();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    while (q--) {
        int type, u, k;
        cin >> type >> u >> k;
        if (type == 1) {
            int v;
            cin >> v;
            removeEdge(u, v);
            addEdge(u, v);
        } else {
            cout << getKthLargest(u, k) << '\n';
        }
    }

    return 0;
}