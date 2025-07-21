#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 200000 + 5;

vector<int> parent(MAX_N);
vector<int> size(MAX_N, 1);

int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) {
        parent[x] = y;
        size[y] += size[x];
    } else {
        parent[y] = x;
        size[x] += size[y];
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    map<int, vector<int>> adj;

    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            unionSets(u, v);
        } else {
            int root = find(v);
            adj[root].push_back(v);
            sort(adj[root].rbegin(), adj[root].rend());
        }
    }

    for (auto &p : adj) {
        for (int v : p.second) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}