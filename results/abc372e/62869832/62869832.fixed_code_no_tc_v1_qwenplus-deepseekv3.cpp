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

void merge(int u, int v) {
    u = gtf(u);
    v = gtf(v);
    if (u == v) return;
    if (as[u].size() < as[v].size()) swap(u, v);
    fa[v] = u;
    for (int num : as[v]) {
        as[u].push_back(num);
    }
    sort(as[u].rbegin(), as[u].rend());
    if (as[u].size() > 10) {
        as[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        fa[i] = i;
        as[i] = {i};
    }
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = gtf(u);
            if (v > as[root].size()) {
                cout << "-1\n";
            } else {
                cout << as[root][v-1] << "\n";
            }
        }
    }
    return 0;
}