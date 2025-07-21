#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<vector<pair<int, int>>> children; // children[i] will store (parent, weight)

int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]); // Path compression
    return parent[x];
}

void union_sets(int x, int y, int w) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX; // Union by rank can be implemented here if needed
        children[rootX].push_back(make_pair(rootY, w));
        children[rootY].push_back(make_pair(rootX, w));
    }
}

int kth_largest(int v, int k) {
    int rootV = find(v);
    sort(children[rootV].begin(), children[rootV].end(), greater<pair<int, int>>());
    if (k > children[rootV].size()) return -1;
    return children[rootV][k-1].first; // Return the vertex number, not the weight
}

int main() {
    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v >> k;
        if (op == 1) {
            union_sets(u, v, 1); // Union by weight or rank can be handled here
        } else {
            cout << kth_largest(v, k) << endl;
        }
    }
    return 0;
}