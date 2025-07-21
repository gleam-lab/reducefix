#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int find(int u, vector<int>& parent, vector<int>& size) {
    if (parent[u] != u) parent[u] = find(parent[u], parent, size);
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& size, vector<set<int>>& components) {
    int rootU = find(u, parent, size);
    int rootV = find(v, parent, size);

    if (rootU != rootV) {
        // Union by size
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
            components[rootV].insert(to_string(u));
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
            components[rootU].insert(to_string(v));
        }
    }
}

int kthLargest(int vertex, int k, vector<set<int>>& components) {
    int root = find(vertex, parent, size);
    set<int>& comp = components[root];

    if (comp.size() < k) return -1;
    auto it = prev(comp.end()); // Get the k-th largest element
    for (int i = 0; i < k - 1; i++) it = prev(comp.end());
    return stoi(*it);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1), size(n + 1), root(n + 1);
    fill(parent.begin(), parent.end(), i);
    fill(size.begin(), size.end(), 1);

    vector<set<int>> components(n + 1);
    for (int i = 1; i <= n; i++) components[i].insert(to_string(i));

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if (type == 1) {
            unionSets(u, v, parent, size, components);
        } else {
            cin >> k;
            cout << kthLargest(v, k, components) << endl;
        }
    }
    return 0;
}