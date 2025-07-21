#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int v) {
    pq[v].push(-v); // Use negative value for max heap simulation
    while (pq[v].size() > 10) {
        pq[v].pop();
    }
}

int getKthLargest(int v, int k) {
    if (pq[v].size() < k) return -1;
    priority_queue<int, vector<int>, greater<int>> temp = pq[v];
    for (int i = 1; i < k; ++i) {
        temp.pop();
    }
    return -temp.top(); // Return positive value
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        updatePQ(i);
    }

    for (int i = 0; i < q; ++i) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            addEdge(u, v);
            updatePQ(u);
            updatePQ(v);
        } else {
            cout << getKthLargest(v, k) << '\n';
        }
    }

    return 0;
}