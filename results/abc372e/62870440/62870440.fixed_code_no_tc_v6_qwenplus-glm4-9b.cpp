#include<bits/stdc++.h>
using namespace std;
vector<int> edges[200005];
vector<int> vertices[200005];
int n, q;
int fa[200005];

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void union_set(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a != root_b) {
        fa[root_b] = root_a;
        vertices[root_a].insert(vertices[root_b].begin(), vertices[root_b].end());
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        vertices[i].push_back(i);
    }

    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_set(u, v);
        } else {
            if (find(u) != find(v)) {
                cout << -1 << endl;
            } else {
                int common_root = find(v);
                sort(vertices[common_root].begin(), vertices[common_root].end(), greater<int>());
                if (k > vertices[common_root].size()) {
                    cout << -1 << endl;
                } else {
                    cout << vertices[common_root][k - 1] << endl;
                }
            }
        }
    }
    return 0;
}