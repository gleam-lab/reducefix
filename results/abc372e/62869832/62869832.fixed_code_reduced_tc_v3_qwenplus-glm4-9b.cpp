#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MAXK 10

typedef pair<int, int> pii;

int parent[MAXN];
int size[MAXN];
int kth_largest[MAXN][MAXK];
priority_queue<pii, vector<pii>, greater<pii>> pq[MAXN];

int find_set(int x) {
    if (parent[x] != x) parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
}

void add_vertex(int v, int val) {
    int set = find_set(v);
    pq[set].push(pii(val, v));
    while (pq[set].size() > MAXK) {
        pq[set].pop();
    }
}

int query_kth_largest(int v, int k) {
    int set = find_set(v);
    int count = 0;
    while (!pq[set].empty()) {
        int val, vertex;
        tie(val, vertex) = pq[set].top();
        pq[set].pop();
        if (count == k - 1) {
            return vertex;
        }
        count++;
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            cin >> k;
            int res = query_kth_largest(v, k);
            cout << res << '\n';
        }
    }
    return 0;
}