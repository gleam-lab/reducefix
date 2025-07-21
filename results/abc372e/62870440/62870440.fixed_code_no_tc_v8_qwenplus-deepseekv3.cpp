#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int parent[MAXN];
vector<int> top_k[MAXN]; // Each component keeps track of top 10 largest elements

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (top_k[x].size() < top_k[y].size()) {
        swap(x, y);
    }
    // Merge top_k[y] into top_k[x]
    for (int num : top_k[y]) {
        top_k[x].push_back(num);
    }
    // Sort in descending order and keep only top 10
    sort(top_k[x].rbegin(), top_k[x].rend());
    if (top_k[x].size() > 10) {
        top_k[x].resize(10);
    }
    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        top_k[i] = {i};
    }

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (top_k[root].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << top_k[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}