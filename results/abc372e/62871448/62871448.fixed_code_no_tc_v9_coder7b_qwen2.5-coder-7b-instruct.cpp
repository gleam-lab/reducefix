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

void getKthLargest(int v, int k) {
    if (pq[v].size() < k) {
        cout << "-1" << endl;
    } else {
        for (int i = 1; i <= k - 1; ++i) {
            pq[v].pop();
        }
        cout << pq[v].top() << endl;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        pq[i].push(-1); // Initialize with a small value to handle queries for nodes with no connections.
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            getKthLargest(v, k);
        }
    }

    return 0;
}