#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int N = 2e5 + 9;
vector<int> parent(N);
vector<int> size(N);

void init() {
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
    }
}

int query(int v, int k) {
    int root = find(v);
    if (size[root] < k) return -1;
    set<int> adjVertices;
    for (int i = 0; i < N; ++i)
        if (i != v && find(i) == root)
            adjVertices.insert(i);
    auto it = prev(adjVertices.upper_bound(-k)) + 1;
    return *it;
}

int main() {
    init();
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
            unionSets(x, y);
        else
            cout << query(x, y) << endl;
    }
    return 0;
}