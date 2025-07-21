#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> rank;
vector<vector<int>> components;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            components[rootX].insert(end(components[rootX]), components[rootY].begin(), components[rootY].end());
            components[rootX].sort(reverse_order());
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            components[rootY].insert(end(components[rootY]), components[rootX].begin(), components[rootX].end());
            components[rootY].sort(reverse_order());
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
            components[rootX].insert(end(components[rootX]), components[rootY].begin(), components[rootY].end());
            components[rootX].sort(reverse_order());
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    rank.resize(n + 1);
    components.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
        components[i].push_back(i);
    }

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            int rootV = find(v);
            if (k > components[rootV].size()) {
                cout << -1 << '\n';
            } else {
                cout << components[rootV][k-1] << '\n';
            }
        }
    }

    return 0;
}