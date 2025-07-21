#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> top[MAXN];
int parent[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (top[u].size() < top[v].size()) {
        swap(u, v);
    }
    vector<int> merged;
    merge(top[u].begin(), top[u].end(), top[v].begin(), top[v].end(), back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top[u] = merged;
    parent[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (v > (int)top[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << top[root][v - 1] << '\n';
            }
        }
    }
    
    return 0;
}