#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAX_SEGS = 20;

// Array to store union-find information
int par[MAXN];
int size[MAXN];
int max_segment[MAXN];

// find function with path compression
int find(int x) {
    if (x == par[x]) {
        return x;
    }
    par[x] = find(par[x]);  // Path compression
    return par[x];
}

// unite function with union by size
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        par[x] = y;
        size[y] += size[x];
        max_segment[y] = max(max_segment[y], max_segment[x]);
    }
}

// add edge function
void add_edge(int x, int y) {
    unite(x, y);
    max_segment[find(x)] = max(max_segment[find(x)], max(abs(x - y)));
}

// query function to find the k-th largest vertex
int query(int v, int k) {
    int root = find(v);
    if (max_segment[root] < k) {
        return -1;
    }
    return max_segment[root] - k + 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        par[i] = i;
        size[i] = 1;
        max_segment[i] = i;
    }
    int op, u, v, k;
    for (int i = 0; i < q; i++) {
        cin >> op >> u >> v;
        if (op == 1) {
            add_edge(u, v);
        } else {
            cin >> k;
            cout << query(v - 1, k) << endl;  // Convert to 0-based index
        }
    }
    return 0;
}