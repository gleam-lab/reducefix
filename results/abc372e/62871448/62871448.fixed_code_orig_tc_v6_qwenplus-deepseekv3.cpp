#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> parent(MAXN);
vector<vector<int>> top10(MAXN);

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (top10[u].size() < top10[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    top10[u].insert(top10[u].end(), top10[v].begin(), top10[v].end());
    sort(top10[u].rbegin(), top10[u].rend());
    if (top10[u].size() > 10) {
        top10[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top10[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u;
        if (op == 1) {
            cin >> v;
            unite(u, v);
        } else {
            int k;
            cin >> k;
            int root = find(u);
            if (top10[root].size() >= k) {
                cout << top10[root][k - 1] << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }
    
    return 0;
}