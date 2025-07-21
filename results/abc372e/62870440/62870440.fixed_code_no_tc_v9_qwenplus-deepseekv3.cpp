#include <bits/stdc++.h>
using namespace std;

int parent[200005];
vector<int> top[200005];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;
    
    if (top[rootX].size() < top[rootY].size()) {
        swap(rootX, rootY);
    }
    
    vector<int> merged;
    merged.reserve(top[rootX].size() + top[rootY].size());
    merge(top[rootX].begin(), top[rootX].end(), top[rootY].begin(), top[rootY].end(), back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top[rootX] = merged;
    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i] = {i};
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