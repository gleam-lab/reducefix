#include<bits/stdc++.h>
using namespace std;

vector<int> as[200005];
int fa[200005];
int N, Q;

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (as[u].size() < as[v].size()) swap(u, v);
    vector<int> merged;
    merge(as[u].begin(), as[u].end(), as[v].begin(), as[v].end(), back_inserter(merged), greater<int>());
    merged.erase(unique(merged.begin(), merged.end()), merged.end());
    if (merged.size() > 10) merged.resize(10);
    as[u] = merged;
    fa[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        as[i] = {i};
    }
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            u = find(u);
            if (as[u].size() < v) {
                cout << "-1\n";
            } else {
                cout << as[u][v-1] << "\n";
            }
        }
    }
    return 0;
}