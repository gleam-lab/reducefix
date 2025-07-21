#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200005

vector<int> parent(MAXN + 1);
vector<int> size(MAXN + 1);
vector<int> graph[MAXN + 1];

void initialize(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
}

void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);  // Union by size
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
            int root_v = find(v);
            vector<int> &adj = graph[root_v];
            sort(adj.begin(), adj.end(), greater<int>());  // Sort descending

            k--;  // Convert k-1 to zero-based index
            if (k >= 0 && k < adj.size()) {
                cout << adj[k] << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}