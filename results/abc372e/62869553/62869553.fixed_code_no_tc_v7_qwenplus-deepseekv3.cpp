#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> as[MAXN];
int fa[MAXN];

int gtf(int x) {
    if (fa[x] != x) {
        fa[x] = gtf(fa[x]);
    }
    return fa[x];
}

void unite(int u, int v) {
    u = gtf(u);
    v = gtf(v);
    if (u == v) return;
    if (as[u].size() < as[v].size()) {
        swap(u, v);
    }
    vector<int> merged;
    int i = 0, j = 0;
    while (i < as[u].size() && j < as[v].size() && merged.size() < 10) {
        if (as[u][i] > as[v][j]) {
            merged.push_back(as[u][i]);
            i++;
        } else {
            merged.push_back(as[v][j]);
            j++;
        }
    }
    while (i < as[u].size() && merged.size() < 10) {
        merged.push_back(as[u][i]);
        i++;
    }
    while (j < as[v].size() && merged.size() < 10) {
        merged.push_back(as[v][j]);
        j++;
    }
    as[u] = merged;
    fa[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        as[i] = {i};
    }
    
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = gtf(u);
            if (as[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << as[root][v - 1] << "\n";
            }
        }
    }
    
    return 0;
}