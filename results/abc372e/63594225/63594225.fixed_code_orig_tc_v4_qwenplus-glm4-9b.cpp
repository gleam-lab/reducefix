#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

int parent[MAXN];
int size[MAXN];

// Initialize the union-find structure
void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

// Find the root of the set
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Union by size
void unite(int x, int y) {
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

// Query the k-th largest element in the component
int query(int v, int k) {
    int root = find(v);
    if (size[root] < k) return -1;
    vector<int> components;
    for (int i = 1; i <= size[root]; i++) {
        components.push_back(find(i));
    }
    sort(components.rbegin(), components.rend()); // Sort in descending order
    return components[k - 1]; // Return the k-th largest component
}

int main() {
    int n, q;
    cin >> n >> q;
    init(n);
    while (q--) {
        int t, v, k;
        cin >> t >> v >> k;
        if (t == 1) {
            cin >> v; // Read the other vertex since it's not provided
            unite(v, v + n - 1); // Union the current vertex with itself
        } else {
            cout << query(v, k) << '\n';
        }
    }
    return 0;
}