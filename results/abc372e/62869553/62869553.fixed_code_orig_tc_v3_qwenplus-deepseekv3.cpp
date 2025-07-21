#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXK = 10;

int parent[MAXN];
vector<int> top[MAXN];

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
    
    if (top[u].size() < top[v].size()) {
        swap(u, v);
    }
    
    vector<int> merged;
    merge(top[u].begin(), top[u].end(), top[v].begin(), top[v].end(), back_inserter(merged));
    sort(merged.rbegin(), merged.rend());
    if (merged.size() > MAXK) {
        merged.resize(MAXK);
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
            merge(u, v);
        } else {
            int root = find(u);
            if (v > (int)top[root].size()) {
                cout << "-1\n";
            } else {
                cout << top[root][v - 1] << "\n";
            }
        }
    }
    
    return 0;
}