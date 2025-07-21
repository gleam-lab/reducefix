#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int parent[MAXN];
vector<int> component[MAXN]; // Stores top 10 elements of each component's vertices

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
    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    component[u].insert(component[u].end(), component[v].begin(), component[v].end());
    sort(component[u].begin(), component[u].end(), greater<int>());
    if (component[u].size() > 10) {
        component[u].resize(10);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i] = {i};
    }

    while (Q--) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            merge(u, v);
        } else {
            cin >> v >> k;
            int root = find(v);
            if (component[root].size() < k) {
                cout << "-1\n";
            } else {
                cout << component[root][k-1] << "\n";
            }
        }
    }

    return 0;
}