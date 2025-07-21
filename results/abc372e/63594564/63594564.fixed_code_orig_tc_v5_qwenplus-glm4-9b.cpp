#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 200001
#define Q 200001

vector<int> parent(N), size(N), list(N);

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        merge(list[u].begin(), list[u].end(), list[v].begin(), list[v].end());
        // Keep the list sorted
        sort(list[u].begin(), list[u].end(), greater<int>());
    }
}

int kth_largest(int u, int k) {
    u = find(u);
    if (k > size[u]) return -1;
    return list[u][k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        list[i].push_back(i);
    }

    for (int i = 0; i < q; ++i) {
        int t, u, v, k;
        cin >> t >> u >> v;
        if (t == 1) {
            unite(u, v);
        } else {
            cin >> k;
            cout << kth_largest(v, k) << endl;
        }
    }

    return 0;
}