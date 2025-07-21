#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
vector<int> parent(MAX_N);
vector<vector<int>> top(MAX_N, vector<int>());

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (top[u].size() < top[v].size()) {
        swap(u, v);
    }
    vector<int> merged;
    int i = 0, j = 0;
    while (i < top[u].size() && j < top[v].size() && merged.size() < 10) {
        if (top[u][i] > top[v][j]) {
            merged.push_back(top[u][i++]);
        } else {
            merged.push_back(top[v][j++]);
        }
    }
    while (i < top[u].size() && merged.size() < 10) {
        merged.push_back(top[u][i++]);
    }
    while (j < top[v].size() && merged.size() < 10) {
        merged.push_back(top[v][j++]);
    }
    top[u] = merged;
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (v > top[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << top[root][v - 1] << '\n';
            }
        }
    }
    
    return 0;
}