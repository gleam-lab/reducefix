#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXK = 10;

int parent[MAXN];
vector<int> top[MAXN];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (top[u].size() < top[v].size())
        swap(u, v);

    parent[v] = u;
    for (int x : top[v]) {
        top[u].push_back(x);
    }
    sort(top[u].rbegin(), top[u].rend());
    if (top[u].size() > MAXK)
        top[u].resize(MAXK);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i].clear();
        top[i].push_back(i);
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            u = find(u);
            if (top[u].size() < v) {
                cout << "-1\n";
            } else {
                cout << top[u][v-1] << "\n";
            }
        }
    }

    return 0;
}