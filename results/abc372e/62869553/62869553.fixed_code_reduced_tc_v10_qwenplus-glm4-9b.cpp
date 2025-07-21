#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;

vector<int> parent(MAX_N);
vector<vector<int>> graph(MAX_N);
vector<vector<int>> componentVertices;

int findRoot(int x) {
    if (parent[x] == x) return x;
    parent[x] = findRoot(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int rootU = findRoot(u);
    int rootV = findRoot(v);
    if (rootU != rootV) {
        parent[rootV] = rootU;
        componentVertices[rootU].insert(componentVertices[rootU].end(), componentVertices[rootV].begin(), componentVertices[rootV].end());
        sort(componentVertices[rootU].begin(), componentVertices[rootU].end());
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        componentVertices.push_back({i});
    }
    
    int u, v, k;
    
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        if (u == 1) {
            unite(u, v);
        } else {
            cin >> k;
            int rootV = findRoot(v);
            if (k > componentVertices[rootV].size()) {
                cout << "-1\n";
            } else {
                cout << componentVertices[rootV][componentVertices[rootV].size() - k] << "\n";
            }
        }
    }
    
    return 0;
}