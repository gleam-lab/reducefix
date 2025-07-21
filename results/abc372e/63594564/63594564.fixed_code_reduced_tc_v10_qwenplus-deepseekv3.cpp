#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<vector<int>> top_k;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    if (top_k[a].size() < top_k[b].size())
        swap(a, b);
    vector<int> merged;
    int i = 0, j = 0;
    while (i < top_k[a].size() && j < top_k[b].size() && merged.size() < 10) {
        if (top_k[a][i] > top_k[b][j]) {
            merged.push_back(top_k[a][i]);
            i++;
        } else {
            merged.push_back(top_k[b][j]);
            j++;
        }
    }
    while (i < top_k[a].size() && merged.size() < 10) {
        merged.push_back(top_k[a][i]);
        i++;
    }
    while (j < top_k[b].size() && merged.size() < 10) {
        merged.push_back(top_k[b][j]);
        j++;
    }
    top_k[a] = merged;
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    top_k.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        top_k[i] = {i};
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (top_k[root].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << top_k[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}