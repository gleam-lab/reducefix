#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 10;
int parent[MAXN], rank[MAXN], size[MAXN];

// Initialize the Union-Find structure
void init(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }
}

// Find the root of the set containing x
int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union the sets containing x and y
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }
        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
}

// Query the k-th largest vertex in the set containing x
int query_kth_largest(int x, int k) {
    int root = find(x);
    vector<int> vertices;
    for (int i = 0; i < size[root]; ++i) {
        vertices.push_back(root + i);
    }
    sort(vertices.rbegin(), vertices.rend());
    if (k > size[root]) {
        return -1;
    }
    return vertices[k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            cin >> v >> k;
            cout << query_kth_largest(v - 1, k) + 1 << endl;
        }
    }

    return 0;
}