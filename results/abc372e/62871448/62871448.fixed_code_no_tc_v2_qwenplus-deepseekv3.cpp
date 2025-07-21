#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int fa[MAXN];
vector<int> top[MAXN]; // Each component's root stores the top 10 elements in descending order

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (top[u].size() < top[v].size()) swap(u, v);
    vector<int> merged;
    int i = 0, j = 0;
    while ((i < top[u].size() || j < top[v].size()) && merged.size() < 10) {
        if (i < top[u].size() && (j >= top[v].size() || top[u][i] >= top[v][j])) {
            merged.push_back(top[u][i]);
            i++;
        } else {
            merged.push_back(top[v][j]);
            j++;
        }
    }
    top[u] = merged;
    fa[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
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