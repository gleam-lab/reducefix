#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
vector<int> top_k[MAXN];

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
    if (top_k[u].size() < top_k[v].size()) {
        swap(u, v);
    }
    vector<int> merged;
    merged.reserve(10);
    int i = 0, j = 0;
    while (merged.size() < 10 && (i < top_k[u].size() || j < top_k[v].size())) {
        if (i < top_k[u].size() && (j >= top_k[v].size() || top_k[u][i] >= top_k[v][j])) {
            merged.push_back(top_k[u][i++]);
        } else {
            merged.push_back(top_k[v][j++]);
        }
    }
    top_k[u] = merged;
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_k[i] = {i};
    }
    while (Q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (top_k[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << top_k[root][v - 1] << "\n";
            }
        }
    }
    return 0;
}