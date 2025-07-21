#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> top[MAXN]; // Each root maintains a sorted list of up to 10 largest elements in descending order
int fa[MAXN];

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (top[u].size() < top[v].size()) swap(u, v);
    // Merge v into u
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        top[i].push_back(i);
    }
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (v > top[root].size()) {
                cout << "-1\n";
            } else {
                cout << top[root][v - 1] << "\n";
            }
        }
    }
    return 0;
}