#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void processQueries(int n, int q) {
    for (int i = 0; i < q; ++i) {
        int type, v, k;
        cin >> type >> v;
        if (type == 1) {
            cin >> k;
            addEdge(v, k);
            pq[v].push(k);
            pq[k].push(v);
        } else if (type == 2) {
            cin >> k;
            while (!pq[v].empty() && pq[v].top() != v) pq[v].pop();
            if (pq[v].size() >= k) cout << pq[v].nth(k - 1) << '\n';
            else cout << -1 << '\n';
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    processQueries(n, q);
    return 0;
}