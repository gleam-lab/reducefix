#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updateHeap(int v, int k) {
    while (!pq[v].empty() && pq[v].size() > k) {
        pq[v].pop();
    }
}

void processQueries(int n, int q) {
    for (int i = 0; i < q; ++i) {
        int op, v, k;
        cin >> op >> v >> k;
        if (op == 1) {
            int u = v;
            cin >> v;
            addEdge(u, v);

            // Update the heaps
            updateHeap(u, k);
            updateHeap(v, k);

            for (auto neighbor : adj[u]) {
                pq[neighbor].push(v);
                updateHeap(neighbor, k);
            }

            for (auto neighbor : adj[v]) {
                pq[neighbor].push(u);
                updateHeap(neighbor, k);
            }
        } else {
            if (adj[v].size() < k) {
                cout << "-1" << endl;
            } else {
                auto it = pq[v].begin();
                advance(it, k - 1);
                cout << *it << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    processQueries(n, q);

    return 0;
}