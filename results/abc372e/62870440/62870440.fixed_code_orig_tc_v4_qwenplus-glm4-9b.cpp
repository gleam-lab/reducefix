#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;
int parent[MAX_N], rank[MAX_N];

// Initialize the union-find structure
void initialize(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find the root of the set containing x with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union by rank of two sets
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX] += 1;
        }
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
            unionSets(u, v);
        } else if (type == 2) {
            int rootV = find(v);
            vector<int> connectedVertices;
            for (int i = 1; i <= n; ++i) {
                if (find(i) == rootV) {
                    connectedVertices.push_back(i);
                }
            }
            if (k <= connectedVertices.size()) {
                cout << connectedVertices[connectedVertices.size() - k] << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}