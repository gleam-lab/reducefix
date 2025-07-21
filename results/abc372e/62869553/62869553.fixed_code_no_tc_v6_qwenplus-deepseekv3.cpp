#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN], size[MAXN];
vector<int> top[MAXN];

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
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    vector<int> merged = top[x];
    merged.insert(merged.end(), top[y].begin(), top[y].end());
    sort(merged.rbegin(), merged.rend());
    if (merged.size() > 10) merged.resize(10);
    top[x] = merged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
        top[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
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