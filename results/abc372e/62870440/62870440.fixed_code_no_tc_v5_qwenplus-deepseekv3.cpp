#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

int parent[MAX_N];
vector<int> components[MAX_N];

int find_root(int x) {
    if (parent[x] != x) {
        parent[x] = find_root(parent[x]);
    }
    return parent[x];
}

void merge(int u, int v) {
    int root_u = find_root(u);
    int root_v = find_root(v);
    if (root_u == root_v) return;
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
    }
    parent[root_v] = root_u;
    components[root_u].insert(components[root_u].end(), components[root_v].begin(), components[root_v].end());
    sort(components[root_u].rbegin(), components[root_u].rend());
    if (components[root_u].size() > 10) {
        components[root_u].resize(10);
    }
    components[root_v].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find_root(u);
            if (v > (int)components[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << components[root][v - 1] << '\n';
            }
        }
    }
    
    return 0;
}