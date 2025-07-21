#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int parent[MAXN];
vector<int> topK[MAXN];

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
    if (topK[u].size() < topK[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    vector<int> merged;
    merged.reserve(topK[u].size() + topK[v].size());
    merge(topK[u].begin(), topK[u].end(), topK[v].begin(), topK[v].end(), back_inserter(merged), greater<int>());
    if (merged.size() > K) {
        merged.resize(K);
    }
    topK[u] = merged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topK[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (v > topK[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << topK[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}