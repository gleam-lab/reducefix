#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
int parent[MAXN], size[MAXN];

// Function to find the root of the set containing v, with path compression
int find(int v) {
    if (parent[v] != v) {
        parent[v] = find(parent[v]);  // Path compression
    }
    return parent[v];
}

// Function to merge two sets containing x and y
void unionSets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);  // Ensure x is the root of the larger set
        }
        parent[y] = x;  // Merge y's set into x's
        size[x] += size[y];  // Update the size of the merged set
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    fill(parent, parent + MAXN, i);  // Initialize parent pointers
    fill(size, size + MAXN, 1);  // Initialize size

    vector<int> ans;
    int op, u, v, k;
    while (q--) {
        cin >> op >> u >> v;
        if (op == 1) {  // Adding an edge
            unionSets(u, v);
        } else if (op == 2) {  // Query for the k-th largest neighbor
            int root = find(v);
            vector<int> component;
            for (int i = 1; i <= n; ++i) {
                if (find(i) == root && i != v) {
                    component.push_back(i);
                }
            }
            sort(component.rbegin(), component.rend());  // Sort in descending order
            if (k <= component.size()) {
                ans.push_back(component[k - 1]);
            } else {
                ans.push_back(-1);
            }
        }
    }

    for (int num : ans) {
        cout << num << '\n';
    }

    return 0;
}