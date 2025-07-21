#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 9;

vector<int> parent(N);
vector<int> rank(N, 1);
vector<set<int>> components;

void unionSets(int u, int v) {
    int root_u = findSet(u);
    int root_v = findSet(v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
            components[root_u].insert(v);
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
            components[root_v].insert(u);
        } else {
            parent[root_v] = root_u;
            components[root_u].insert(v);
            rank[root_u]++;
        }
    }
}

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

int kthLargestInComponent(int v, int k) {
    int root_v = findSet(v);
    if (k > components[root_v].size()) {
        return -1;
    }
    return *(--components[root_v].upper_bound(k));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; ++i) {
        int cmd, u, v, k;
        cin >> cmd >> u >> v;

        if (cmd == 1) {
            unionSets(u, v);
        } else {
            cin >> k;
            cout << kthLargestInComponent(v, k) << endl;
        }
    }

    return 0;
}