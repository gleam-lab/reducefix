#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> parent(MAXN), size(MAXN), pq[MAXN];

int getRoot(int u) {
    if (parent[u] == u) return u;
    return parent[u] = getRoot(parent[u]);
}

void unite(int u, int v) {
    u = getRoot(u), v = getRoot(v);
    if (u != v) {
        if (size[u] > size[v]) swap(u, v);
        parent[u] = v;
        size[v] += size[u];
        pq[v].insert(pq[v].end(), pq[u].begin(), pq[u].end());
        pq[u].clear();
        make_heap(begin(pq[v]), end(pq[v]), greater<int>());
    }
}

int kthLargest(int u, int k) {
    u = getRoot(u);
    if (pq[u].size() < k) return -1;
    auto it = pq[u].begin();
    advance(it, pq[u].size() - k);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    iota(parent.begin(), parent.end(), 0);
    fill(size.begin(), size.end(), 1);

    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            --u, --v;
            unite(u, v);
        } else {
            cin >> u >> k;
            --u;
            cout << kthLargest(u, k) << '\n';
        }
    }

    return 0;
}