#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> adj[MAXN];
priority_queue<int> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int v) {
    pq[v].push(-v);
    for (auto neighbor : adj[v]) {
        pq[v].push(-neighbor);
    }
}

int getKthLargest(int v, int k) {
    while (!pq[v].empty() && k > 0) {
        if (-pq[v].top() == v) pq[v].pop();
        else return -pq[v].top();
        k--;
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        updatePQ(i);
    }

    int op, ix, iy;
    for (int i = 0; i < q; ++i) {
        cin >> op >> ix >> iy;
        if (op == 1) {
            addEdge(ix, iy);
            updatePQ(ix);
            updatePQ(iy);
        } else {
            cout << getKthLargest(ix, iy) << "\n";
        }
    }

    return 0;
}