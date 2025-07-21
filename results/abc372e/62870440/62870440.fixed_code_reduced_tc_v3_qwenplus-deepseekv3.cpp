#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int parent[MAXN];
vector<int> topk[MAXN];

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
    if (topk[u].size() < topk[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    vector<int> merged;
    merged.reserve(topk[u].size() + topk[v].size());
    merge(topk[u].begin(), topk[u].end(), topk[v].begin(), topk[v].end(), back_inserter(merged), greater<int>());
    if (merged.size() > K) {
        merged.resize(K);
    }
    topk[u] = merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topk[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (v > topk[root].size()) {
                cout << "-1\n";
            } else {
                cout << topk[root][v - 1] << "\n";
            }
        }
    }

    return 0;
}