#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

int parent[MAXN];
int size[MAXN];
vector<int> top[MAXN];

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
    vector<int> merged;
    merge(top[u].begin(), top[u].end(), top[v].begin(), top[v].end(), back_inserter(merged), greater<int>());
    if (merged.size() > MAXK) merged.resize(MAXK);
    top[u] = merged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
        top[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (top[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << top[root][v - 1] << "\n";
            }
        }
    }
    
    return 0;
}