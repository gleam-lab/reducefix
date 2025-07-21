#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN), rank(MAXN), size(MAXN);
priority_queue<int> pq[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 1;
        size[i] = 1;
        pq[i].push(-i);
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] > rank[y]) {
        swap(x, y);
    }
    parent[x] = y;
    rank[y] += rank[x];
    size[y] += size[x];
    pq[y].merge(pq[x]);
}

int kth_largest(int x, int k) {
    x = find(x);
    if (pq[x].size() < k) return -1;
    auto it = pq[x].begin();
    advance(it, k - 1);
    return -(*it);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            cout << kth_largest(v, u) << '\n';
        }
    }

    return 0;
}