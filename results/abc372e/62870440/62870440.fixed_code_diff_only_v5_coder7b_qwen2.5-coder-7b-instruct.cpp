#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
int as[200005][11];
int fa[200005];
int n,q;

int gtf(int x)
{
    int ret = x;
    while (fa[ret] != ret) ret = fa[ret];
    return ret;
}

void update(int root, int val) {
    for (int i = 1; i <= 10; ++i) {
        if (val > as[root][i]) {
            for (int j = 10; j > i; --j) {
                as[root][j] = as[root][j - 1];
            }
            as[root][i] = val;
            break;
        }
    }
}

int main() {
    cin >> q >> n;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        as[i][0] = i;
        for (int j = 1; j <= 10; ++j) as[i][j] = -1;
    }

    int op, ix, iy;
    for (int i = 0; i < q; i++) {
        cin >> op >> ix >> iy;
        if (op == 1) {
            int rootX = gtf(ix), rootY = gtf(iy);
            if (rootX != rootY) {
                for (auto neighbor : adj[rootY]) {
                    update(rootX, neighbor);
                }
                fa[rootY] = rootX;
                adj[rootX].insert(adj[rootX].end(), adj[rootY].begin(), adj[rootY].end());
                adj[rootY].clear();
            }
        } else {
            cout << as[gtf(ix)][iy - 1] << "\n";
        }
    }
    return 0;
}