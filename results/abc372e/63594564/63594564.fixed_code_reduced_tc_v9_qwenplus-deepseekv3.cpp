#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<vector<int>> components;

int find_root(int x) {
    if (parent[x] != x) {
        parent[x] = find_root(parent[x]);
    }
    return parent[x];
}

void merge(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return;
    if (components[a].size() < components[b].size()) {
        swap(a, b);
    }
    vector<int> merged;
    int i = 0, j = 0;
    while ((i < components[a].size() || j < components[b].size()) && merged.size() < 10) {
        if (j >= components[b].size() || (i < components[a].size() && components[a][i] > components[b][j])) {
            merged.push_back(components[a][i]);
            i++;
        } else {
            merged.push_back(components[b][j]);
            j++;
        }
    }
    components[a] = merged;
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    components.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i] = {i};
    }
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            merge(a, b);
        } else {
            a = find_root(a);
            if (components[a].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << components[a][b - 1] << '\n';
            }
        }
    }
    return 0;
}