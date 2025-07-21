#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int parent[MAXN], size[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

int merge(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) swap(root_u, root_v);
        parent[root_v] = root_u;
        size[root_u] += size[root_v];
        return size[root_u];
    }
    return size[root_u];
}

void add_edge(int u, int v) {
    merge(u, v);
}

int kth_largest(int v, int k) {
    int root_v = find(v);
    if (k > size[root_v]) return -1;
    // Sorting is needed to find the k-th largest element
    vector<int> component;
    for (int i = 1; i <= MAXN; ++i) {
        if (find(i) == root_v) {
            component.push_back(i);
        }
    }
    sort(component.rbegin(), component.rend());
    return component[k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            add_edge(u, v);
        } else if (op == 2) {
            cin >> k;
            cout << kth_largest(u, k) << endl;
        }
    }
    return 0;
}