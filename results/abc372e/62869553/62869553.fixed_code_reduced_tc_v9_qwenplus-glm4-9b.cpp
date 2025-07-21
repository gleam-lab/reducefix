#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20021; // Reduce the size of the as array
int as[MAXN][21];
int fa[MAXN];
int n, q;

int gtf(int x) {
    if (fa[x] != x) fa[x] = gtf(fa[x]); // Path compression
    return fa[x];
}

void union_vertices(int x, int y) {
    int rootX = gtf(x);
    int rootY = gtf(y);
    if (rootX != rootY) {
        fa[rootY] = rootX;
        for (int i = 0; i < 21; i++) {
            as[rootX][i + 10] = as[rootY][i];
        }
        sort(as[rootX] + 10, as[rootX] + 31, greater<int>());
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        for (int j = 0; j < 21; j++) as[i][j] = -1;
    }
    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_vertices(u, v);
        } else {
            k = gtf(v);
            if (k != v) {
                if (k < 1 || k > 10) cout << -1 << endl;
                else cout << as[k][10 + k - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}