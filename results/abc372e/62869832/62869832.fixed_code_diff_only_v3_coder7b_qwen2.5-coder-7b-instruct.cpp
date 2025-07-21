#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            pq[u].push(v);
            pq[v].push(u);
            while (pq[u].size() > 10) pq[u].pop();
            while (pq[v].size() > 10) pq[v].pop();
        } else {
            if (pq[u].size() < v) cout << -1 << endl;
            else {
                for (int j = 0; j < v - 1; j++) pq[u].pop();
                cout << pq[u].top() << endl;
            }
        }
    }
    return 0;
}