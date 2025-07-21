#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

vector<int> as[MAX_N];
int fa[MAX_N];
int n, q;

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
    fa[y] = x;
    as[x].insert(as[x].end(), as[y].begin(), as[y].end());
    sort(as[x].begin(), as[x].end(), greater<int>());
    if (as[x].size() > 10) {
        as[x].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        as[i].push_back(i);
    }
    while (q--) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            merge(u, v);
        } else {
            cin >> v >> k;
            int root = find(v);
            if (k > as[root].size()) {
                cout << -1 << "\n";
            } else {
                cout << as[root][k-1] << "\n";
            }
        }
    }
    return 0;
}