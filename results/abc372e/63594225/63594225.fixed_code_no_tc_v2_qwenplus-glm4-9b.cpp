#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 200005

vector<int> edges[N];
vector<int> tree[N]; // To hold the tree structure
int parent[N];

int find_root(int node) {
    if (parent[node] != node) {
        parent[node] = find_root(parent[node]);
    }
    return parent[node];
}

void union_nodes(int u, int v) {
    u = find_root(u);
    v = find_root(v);
    if (u == v) return;

    if (edges[v].size() < edges[u].size()) {
        swap(u, v);
    }

    for (int num : edges[u]) {
        tree[v].push_back(num);
        sort(tree[v].rbegin(), tree[v].rend());
    }

    parent[u] = v;
    edges[u].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            union_nodes(a, b);
        } else {
            int root = find_root(b);
            int size = tree[root].size();
            if (b <= size) {
                cout << tree[root][size - b] << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}