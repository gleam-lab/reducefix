#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int u) {
    pq[u].reset();
    for (int v : adj[u]) {
        if (!pq[v].empty()) {
            pq[u].push(-pq[v].top());
        }
    }
}

int getKthLargest(int u, int k) {
    if (pq[u].size() < k) return -1;
    vector<int> temp;
    while (k--) {
        temp.push_back(-pq[u].top());
        pq[u].pop();
    }
    for (int val : temp) pq[u].push(val);
    return temp.back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        pq[i].push(i);
    }

    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            addEdge(u, v);
            updatePQ(u);
            updatePQ(v);
        } else {
            cout << getKthLargest(u, v) << '\n';
        }
    }

    return 0;
}