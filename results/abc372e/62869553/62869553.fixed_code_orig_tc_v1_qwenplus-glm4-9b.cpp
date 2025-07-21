#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;

int parent[MAX_N];
int size[MAX_N];
vector<int> adj[MAX_N];

void initialize(int n) {
    fill(parent, parent + n, -1);
    fill(size, size + n, 1);
}

int find(int x) {
    if (parent[x] == -1) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    initialize(n);

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if (type == 1) {
            union_sets(u, v);
        } else if (type == 2) {
            int root = find(v);
            sort(adj[root].rbegin(), adj[root].rend());
            if (k > adj[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << adj[root][k - 1] << '\n';
            }
        }
    }

    return 0;
}