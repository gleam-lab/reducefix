#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> parents(MAXN);
vector<vector<int>> children(MAXN);

int root(int v) {
    if (v == parents[v]) return v;
    return parents[v] = root(parents[v]);
}

void union_sets(int u, int v) {
    int root_u = root(u);
    int root_v = root(v);
    if (root_u != root_v) {
        parents[root_v] = root_u;
    }
}

void find_kth_largest(int v, int k) {
    int count = 0;
    for (int child : children[v]) {
        count++;
        if (count == k) {
            cout << child << endl;
            return;
        }
        find_kth_largest(child, k);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parents[i] = i;
    }
    int u, v, k;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v >> k;
        if (u == 1) {
            union_sets(u, v);
        } else if (u == 2) {
            find_kth_largest(v, k);
        }
    }
    return 0;
}