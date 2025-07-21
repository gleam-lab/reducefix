#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 200005

vector<int> edges[MAXN];
vector<int> component[MAXN];
int parent[MAXN];
int rank[MAXN];
int size[MAXN];

int find_set(int x) {
    if (parent[x] != x) {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x != y) {
        if (rank[x] < rank[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[y] = x;
            size[x] += size[y];
            rank[x]++;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }
    
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            union_sets(u, v);
        } else {
            if (find_set(u) == find_set(v)) {
                cout << v << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    
    return 0;
}