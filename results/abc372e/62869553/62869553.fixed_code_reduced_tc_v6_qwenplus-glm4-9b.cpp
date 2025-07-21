#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN], size[MAXN];

// Find the representative of the set containing x
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Union the sets containing x and y
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            unionSets(u, v);
        } else if (op == 2) {
            int rootV = find(v);
            vector<int> components;
            for (int i = 1; i <= n; i++) {
                if (find(i) == rootV) {
                    components.push_back(i);
                }
            }
            sort(components.rbegin(), components.rend()); // Sort in descending order
            if (k > components.size()) {
                cout << -1 << endl;
            } else {
                cout << components[k - 1] << endl;
            }
        }
    }
    return 0;
}