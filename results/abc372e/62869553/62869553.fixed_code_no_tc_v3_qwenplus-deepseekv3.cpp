#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> as[MAXN];
int fa[MAXN];

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (as[x].size() < as[y].size()) {
        swap(x, y);
    }
    vector<int> merged;
    merged.reserve(as[x].size() + as[y].size());
    merge(as[x].begin(), as[x].end(), as[y].begin(), as[y].end(), back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    as[x] = merged;
    fa[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
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
            int root = find(u);
            if (v > as[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << as[root][v - 1] << '\n';
            }
        }
    }
    
    return 0;
}