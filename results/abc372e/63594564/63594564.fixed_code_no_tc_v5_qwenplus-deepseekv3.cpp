#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> parent;
vector<vector<int>> top_nodes;

int find_par(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_par(parent[x]);
}

void unite(int a, int b) {
    a = find_par(a);
    b = find_par(b);
    if (a == b) return;
    if (top_nodes[a].size() < top_nodes[b].size()) {
        swap(a, b);
    }
    vector<int> merged;
    int i = 0, j = 0;
    while ((i < top_nodes[a].size() || j < top_nodes[b].size()) && merged.size() < 10) {
        if (j >= top_nodes[b].size() || (i < top_nodes[a].size() && top_nodes[a][i] >= top_nodes[b][j])) {
            merged.push_back(top_nodes[a][i]);
            i++;
        } else {
            merged.push_back(top_nodes[b][j]);
            j++;
        }
    }
    top_nodes[a] = merged;
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    top_nodes.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        top_nodes[i] = {i};
    }
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            unite(u, v);
        } else {
            int root = find_par(u);
            if (top_nodes[root].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << top_nodes[root][v - 1] << '\n';
            }
        }
    }
    return 0;
}