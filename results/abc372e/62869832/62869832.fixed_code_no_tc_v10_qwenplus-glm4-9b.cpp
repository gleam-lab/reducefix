#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAX_TREE_SIZE = 20;
int parent[MAXN]; // To store the parent of each vertex
int size[MAXN]; // To store the size of each subtree
int rank[MAXN]; // To store the rank of each subtree

// Function to find the root of the tree
int findSet(int x) {
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]); // Path compression
    }
    return parent[x];
}

// Function to union two sets
void unionSet(int x, int y) {
    int rootX = findSet(x);
    int rootY = findSet(y);
    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++; // Increase the rank if ranks are equal
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            // Connect vertices u and v
            unionSet(u, v);
        } else if (op == 2) {
            // Find the k-th largest vertex connected to v
            int rootV = findSet(v);
            if (size[rootV] < k) {
                cout << -1 << endl;
            } else {
                // Create a sorted list of children of rootV
                vector<int> sortedChildren;
                for (int i = 1; i <= n; i++) {
                    if (findSet(i) == rootV && i != v) {
                        sortedChildren.push_back(i);
                    }
                }
                sort(sortedChildren.begin(), sortedChildren.end(), greater<int>());

                // Output the k-th largest element
                cout << sortedChildren[k - 1] << endl;
            }
        }
    }
    return 0;
}