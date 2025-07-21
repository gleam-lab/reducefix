#include <bits/stdc++.h>
using namespace std;

const int MAXK = 10;
const int MAXN = 2e5 + 5;

int parent[MAXN];
vector<int> topk[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets' top-k lists while maintaining descending order
void unite(int u, int v) {
    int ru = find(u);
    int rv = find(v);
    if (ru == rv) return;

    // Always attach smaller rank to larger rank
    static vector<int> merged;
    merged.clear();
    int i = 0, j = 0;
    for (; i < (int)topk[ru].size() && j < (int)topk[rv].size();) {
        if (merged.size() >= MAXK) break;
        if (topk[ru][i] > topk[rv][j])
            merged.push_back(topk[ru][i++]);
        else
            merged.push_back(topk[rv][j++]);
    }

    while (i < (int)topk[ru].size() && merged.size() < MAXK)
        merged.push_back(topk[ru][i++]);
    while (j < (int)topk[rv].size() && merged.size() < MAXK)
        merged.push_back(topk[rv][j++]);

    // Attach smaller tree to larger tree
    if (topk[ru].size() >= topk[rv].size()) {
        parent[rv] = ru;
        topk[ru] = merged;
    } else {
        parent[ru] = rv;
        topk[rv] = merged;
    }
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

    for (int q = 0; q < Q; ++q) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (op == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if ((int)topk[root].size() < k)
                cout << -1 << '\n';
            else
                cout << topk[root][k - 1] << '\n';
        }
    }

    return 0;
}