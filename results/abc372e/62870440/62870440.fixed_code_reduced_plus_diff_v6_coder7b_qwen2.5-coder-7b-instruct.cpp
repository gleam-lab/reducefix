#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN), size(MAXN), *sets[MAXN];

void init(int n) {
    iota(parent.begin(), parent.end(), 0);
    fill(size.begin(), size.end(), 1);
    for (int i = 0; i <= n; ++i) sets[i].clear();
}

int find(int u) {
    if (parent[u] != u) return parent[u] = find(parent[u]);
    return u;
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    
    if (size[u] > size[v]) swap(u, v);
    parent[u] = v;
    size[v] += size[u];
    sets[v].insert(sets[u].begin(), sets[u].end());
    sets[v].insert(v);
    while (sets[v].size() > 10) sets[v].erase(sets[v].begin());
}

int kthLargest(int v, int k) {
    v = find(v);
    if (v == -1 || k > 10 || sets[v].size() < k) return -1;
    return *next(sets[v].rbegin(), k - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    init(n);
    
    for (int i = 0; i < q; ++i) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            merge(u, v);
        } else {
            cout << kthLargest(v, v) << '\n';
        }
    }
    
    return 0;
}