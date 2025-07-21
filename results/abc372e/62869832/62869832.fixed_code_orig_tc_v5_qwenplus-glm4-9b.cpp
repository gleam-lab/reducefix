#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN), size(MAXN), weight(MAXN);
vector<vector<int>> component(MAXN);

int find_root(int x) {
    if (x == parent[x]) return x;
    parent[x] = find_root(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find_root(x);
    int rootY = find_root(y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            rootX = rootY;
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        component[rootX].insert(weight[rootY]);
    }
}

int kth_largest(int v, int k) {
    int rootV = find_root(v);
    set<int> sorted(component[rootV]);
    int count = 0;
    for (int w : sorted) {
        if (++count == k) return w;
    }
    return -1; // If k is out of bounds
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        weight[i] = i;
    }
    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            cin >> k;
            cout << kth_largest(u, k) << '\n';
        }
    }
    return 0;
}