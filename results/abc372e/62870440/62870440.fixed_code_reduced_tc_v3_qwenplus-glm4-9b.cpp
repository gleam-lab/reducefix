#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
int par[MAXN], rank[MAXN];

void make_set() {
    for (int i = 0; i < MAXN; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (x == par[x]) return x;
    par[x] = find(par[x]); // Path compression
    return par[x];
}

void unite(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root != y_root) {
        if (rank[x_root] < rank[y_root]) {
            swap(x_root, y_root);
        }
        par[x_root] = y_root;
        if (rank[x_root] == rank[y_root]) {
            rank[y_root]++;
        }
    }
}

pair<int, vector<int>> get_kth_largest(int v, int k) {
    int root = find(v);
    int count = 0;
    for (int i = 0; count < k && i < rank[root]; i++) {
        count += find(as[root][i]) == root;
    }
    if (count < k) return {-1, {}};
    else {
        vector<int> res(rank[root] - count);
        for (int i = rank[root] - 1; i >= rank[root] - count; i--) {
            res[rank[root] - count - (i - rank[root] + 1)] = as[root][i];
        }
        return {0, res};
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    make_set();

    vector<vector<int>> tree_as(MAXN);
    for (int i = 0; i < q; i++) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            auto [status, res] = get_kth_largest(v, v);
            if (status == -1) cout << -1 << '\n';
            else {
                for (int num : res) cout << num << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}