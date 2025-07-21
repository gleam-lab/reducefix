#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];
int n, q;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int v) {
    pq[v].push(-v);
    while (pq[v].size() > 10) pq[v].pop();
}

void solveQueries() {
    cin >> q >> n;
    for (int i = 0; i < q; ++i) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        if (op == 1) {
            addEdge(ix, iy);
            updatePQ(ix);
            updatePQ(iy);
        } else {
            if (pq[ix].size() < iy) cout << -1 << '\n';
            else cout << -pq[ix].top() << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solveQueries();
    return 0;
}