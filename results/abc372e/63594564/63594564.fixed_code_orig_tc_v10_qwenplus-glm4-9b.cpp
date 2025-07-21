#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define N 200005

vector<int> parent(N);
multiset<int, greater<int>> component[N];

int find_parent(int v) {
    if (parent[v] == v) return v;
    parent[v] = find_parent(parent[v]);
    return parent[v];
}

void union_vertices(int u, int v) {
    int root_u = find_parent(u);
    int root_v = find_parent(v);

    if (root_u != root_v) {
        parent[root_v] = root_u;
        component[root_u].insert(v);
    }
}

int kth_largest(int v, int k) {
    int root_v = find_parent(v);
    if (component[root_v].size() < k) return -1;
    auto it = component[root_v].upper_bound(k);
    return *(--it);
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < q; ++i) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            union_vertices(x, y);
        } else {
            int result = kth_largest(y, x);
            cout << result << '\n';
        }
    }

    return 0;
}