#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
set<int> components[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return;

    // Always merge smaller set into larger one to optimize time complexity
    if (components[rootX].size() < components[rootY].size()) {
        swap(rootX, rootY);
    }

    // Merge the two sets
    for (int val : components[rootY]) {
        components[rootX].insert(val);
    }
    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and component sets
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if ((int)components[root].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = components[root].end();
                advance(it, -(k));
                cout << *it << '\n';
            }
        }
    }

    return 0;
}