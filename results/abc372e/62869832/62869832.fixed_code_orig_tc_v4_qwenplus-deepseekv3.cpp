#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> largest[MAXN];
int parent[MAXN];
int n, q;

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
    if (largest[u].size() < largest[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    largest[u].insert(largest[u].end(), largest[v].begin(), largest[v].end());
    sort(largest[u].begin(), largest[u].end(), greater<int>());
    if (largest[u].size() > 10) {
        largest[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        largest[i] = {i};
    }

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            u = find(u);
            if (largest[u].size() < v) {
                cout << "-1\n";
            } else {
                cout << largest[u][v-1] << "\n";
            }
        }
    }

    return 0;
}