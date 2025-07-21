#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int KMAX = 10;

int N, Q;
int parent[MAXN];
set<int> components[MAXN]; // Each component stores top KMAX nodes in descending order

// Find the root of the set with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union two sets by size
bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return false;

    // Merge smaller set into larger set to optimize time complexity
    if (components[rootX].size() < components[rootY].size())
        swap(rootX, rootY);

    // Merge the contents of rootY into rootX
    for (int val : components[rootY]) {
        components[rootX].insert(val);
        if (components[rootX].size() > KMAX)
            components[rootX].erase(--components[rootX].end()); // Remove smallest if over capacity
    }

    parent[rootY] = rootX;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;

    // Initialize DSU and each component
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
            if (components[root].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = components[root].end();
                advance(it, -k);
                cout << *it << endl;
            }
        }
    }

    return 0;
}