#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int find(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int kthLargest(vector<int>& connComp, int size, int k) {
    if (k > size || k <= 0) {
        return -1;
    }
    return connComp[connComp.size() - k];
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    vector<vector<int>> connComp;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionSets(u, v, parent, rank);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int rootV = find(v, parent);
            vector<int> comp;
            for (int i = 1; i <= n; ++i) {
                if (find(i, parent) == rootV) {
                    comp.push_back(i);
                }
            }
            sort(comp.rbegin(), comp.rend());
            cout << kthLargest(comp, comp.size(), k) << endl;
        }
    }
    return 0;
}