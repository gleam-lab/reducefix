#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN];
vector<int> topk[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (topk[x].size() < topk[y].size()) {
        swap(x, y);
    }
    vector<int> merged;
    merge(topk[x].begin(), topk[x].end(), topk[y].begin(), topk[y].end(), back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    topk[x] = merged;
    parent[y] = x;
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
            unite(u, v);
        } else {
            int root = find(u);
            if (v > topk[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << topk[root][v - 1] << '\n';
            }
        }
    }
    return 0;
}