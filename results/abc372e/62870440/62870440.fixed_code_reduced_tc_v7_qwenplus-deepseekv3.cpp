#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
int size[MAXN];
multiset<int> top_elements[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (size[u] < size[v]) swap(u, v);
    parent[v] = u;
    size[u] += size[v];
    top_elements[u].insert(top_elements[v].begin(), top_elements[v].end());
    top_elements[v].clear();
    while (top_elements[u].size() > 10) {
        top_elements[u].erase(top_elements[u].begin());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
        top_elements[i].insert(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (top_elements[root].size() < v) {
                cout << "-1\n";
            } else {
                auto it = top_elements[root].end();
                advance(it, -v);
                cout << *it << '\n';
            }
        }
    }
    
    return 0;
}