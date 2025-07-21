#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 200005
using namespace std;

vector<vector<int>> adj(MAX);
set<int> components[MAX];
int root[MAX];

int findRoot(int x) {
    if (root[x] != x) root[x] = findRoot(root[x]);
    return root[x];
}

void unite(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x != y) {
        if (components[x].size() < components[y].size()) swap(x, y);
        for (int v : components[x]) components[y].insert(v);
        components[x].clear();
        root[x] = y;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    fill_n(root, n + 1, -1);
    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            u--; v--;
            if (root[u] == -1) {
                root[u] = u;
            }
            if (root[v] == -1) {
                root[v] = v;
            }
            unite(u, v);
        } else {
            cin >> v >> k;
            v--;
            if (components[findRoot(v)].size() < k) {
                cout << -1 << endl;
            } else {
                auto rit = components[findRoot(v)].rbegin();
                advance(rit, k - 1);
                cout << *rit + 1 << endl;
            }
        }
    }
    return 0;
}