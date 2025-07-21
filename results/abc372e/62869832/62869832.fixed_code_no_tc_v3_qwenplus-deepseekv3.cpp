#include<bits/stdc++.h>
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

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (as[x].size() < as[y].size()) {
        swap(x, y);
    }
    fa[y] = x;
    for (int num : as[y]) {
        as[x].push_back(num);
    }
    sort(as[x].begin(), as[x].end(), greater<int>());
    if (as[x].size() > 10) {
        as[x].resize(10);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        fa[i] = i;
        as[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (v > as[root].size()) {
                cout << "-1\n";
            } else {
                cout << as[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}