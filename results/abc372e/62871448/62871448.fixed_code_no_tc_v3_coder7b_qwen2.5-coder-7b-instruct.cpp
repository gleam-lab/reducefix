#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 11;

vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
}

int getKthLargest(int v, int k) {
    while (pq[v].size() > k) pq[v].pop();
    if (pq[v].size() < k) return -1;
    return pq[v].top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        pq[i].push(-1); // Initialize with a small value
    }

    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else {
            cin >> v >> k;
            cout << getKthLargest(v, k) << '\n';
        }
    }

    return 0;
}