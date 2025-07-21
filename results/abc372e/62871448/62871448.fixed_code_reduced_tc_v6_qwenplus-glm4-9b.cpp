#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<vector<int>> size;
vector<vector<int>> connectedVertices;

void initialize(int n) {
    parent.resize(n + 1);
    size.resize(n + 1);
    connectedVertices.resize(n + 1);

    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    int root = find(parent[x]);
    parent[x] = root;
    return root;
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];

        // Add y to the connected vertices of x
        connectedVertices[rootX].push_back(y);
        sort(connectedVertices[rootX].rbegin(), connectedVertices[rootX].rend());
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    initialize(N);

    for (int i = 0; i < Q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;

        if (op == 1) {
            unionSets(u, v);
        } else if (op == 2) {
            int rootV = find(v);
            if (k > connectedVertices[rootV].size()) {
                cout << -1 << '\n';
            } else {
                cout << connectedVertices[rootV][k - 1] << '\n';
            }
        }
    }

    return 0;
}