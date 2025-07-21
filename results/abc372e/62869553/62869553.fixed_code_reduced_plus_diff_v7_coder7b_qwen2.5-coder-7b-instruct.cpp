#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
const int MAXK = 11;

vector<int> adj[MAXN];
priority_queue<int> pq[MAXN];

int parent[MAXN];
int rank[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 1;
        pq[i].push(i);
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (rank[u] > rank[v]) {
        swap(u, v);
    }

    parent[u] = v;
    rank[v] += rank[u];
    while (!pq[u].empty()) {
        pq[v].push(pq[u].top());
        pq[u].pop();
    }
}

int getKthLargest(int u, int k) {
    u = find(u);
    if (k > pq[u].size()) return -1;
    auto it = pq[u].begin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    init(n);

    for (int i = 0; i < q; ++i) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 1) {
            merge(u, v);
        } else {
            cout << getKthLargest(u, v) << '\n';
        }
    }

    return 0;
}