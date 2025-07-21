#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> top[MAXN];
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
    if (top[x].size() < top[y].size()) {
        swap(x, y);
    }
    for (int num : top[y]) {
        top[x].push_back(num);
    }
    sort(top[x].rbegin(), top[x].rend());
    if (top[x].size() > 10) {
        top[x].resize(10);
    }
    fa[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        top[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            merge(u, v);
        } else {
            cin >> v >> k;
            int root = find(v);
            if (k > top[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << top[root][k - 1] << '\n';
            }
        }
    }
    
    return 0;
}