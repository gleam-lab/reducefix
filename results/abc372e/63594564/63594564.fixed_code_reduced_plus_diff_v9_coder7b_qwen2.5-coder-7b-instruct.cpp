#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN], rank[MAXN];
set<int> connections[MAXN];

int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    
    // Always attach smaller tree under larger tree
    if (rank[x] < rank[y]) swap(x, y);
    connections[x].insert(connections[y].begin(), connections[y].end());
    connections[x].insert(y);
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
}

int kthLargest(vector<int>& vec, int k) {
    if (k > vec.size()) return -1;
    auto it = prev(vec.end(), k);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (connections[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << kthLargest(connections[root], v) << "\n";
            }
        }
    }

    return 0;
}