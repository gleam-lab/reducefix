#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<vector<int>> components;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (components[a].size() < components[b].size()) {
        swap(a, b);
    }
    // Merge the smaller component into the larger one
    vector<int> merged;
    int i = 0, j = 0;
    while (i < components[a].size() && j < components[b].size() && merged.size() < 10) {
        if (components[a][i] > components[b][j]) {
            merged.push_back(components[a][i]);
            i++;
        } else {
            merged.push_back(components[b][j]);
            j++;
        }
    }
    while (i < components[a].size() && merged.size() < 10) {
        merged.push_back(components[a][i]);
        i++;
    }
    while (j < components[b].size() && merged.size() < 10) {
        merged.push_back(components[b][j]);
        j++;
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
            unite(a, b);
        } else {
            int root = find(a);
            if (components[root].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << components[root][b - 1] << '\n';
            }
        }
    }

    return 0;
}