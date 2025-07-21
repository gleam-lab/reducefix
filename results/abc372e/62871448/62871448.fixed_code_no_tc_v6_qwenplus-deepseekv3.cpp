#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> top[MAXN];  // Each root stores top 10 largest elements in its component
int fa[MAXN];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (top[u].size() < top[v].size()) swap(u, v);
    vector<int> merged;
    merged.reserve(10);
    int i = 0, j = 0;
    while (i < top[u].size() && j < top[v].size() && merged.size() < 10) {
        if (top[u][i] > top[v][j]) {
            merged.push_back(top[u][i]);
            i++;
        } else {
            merged.push_back(top[v][j]);
            j++;
        }
    }
    while (i < top[u].size() && merged.size() < 10) {
        merged.push_back(top[u][i]);
        i++;
    }
    while (j < top[v].size() && merged.size() < 10) {
        merged.push_back(top[v][j]);
        j++;
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
            merge(u, v);
        } else {
            int root = find(u);
            if (v > top[root].size()) {
                cout << "-1\n";
            } else {
                cout << top[root][v-1] << '\n';
            }
        }
    }
    
    return 0;
}