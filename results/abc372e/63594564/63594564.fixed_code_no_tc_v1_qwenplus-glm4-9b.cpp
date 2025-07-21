#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

vector<int> parent;
vector<vector<int>> adjList;
vector<vector<int>> subtreeSizes;

int findSet(int v) {
    if (parent[v] != v) {
        parent[v] = findSet(parent[v]);
    }
    return parent[v];
}

void unionSets(int v1, int v2) {
    int root1 = findSet(v1);
    int root2 = findSet(v2);
    if (root1 != root2) {
        if (subtreeSizes[root1] < subtreeSizes[root2]) {
            swap(root1, root2);
        }
        parent[root2] = root1;
        subtreeSizes[root1] += subtreeSizes[root2];
    }
}

void buildSubtreeSizes(int root, int parent) {
    subtreeSizes[root] = 1;
    for (int neighbor : adjList[root]) {
        if (neighbor != parent) {
            buildSubtreeSizes(neighbor, root);
            subtreeSizes[root] += subtreeSizes[neighbor];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    adjList.resize(n + 1);
    subtreeSizes.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if (type == 1) {
            // Union operation
            if (findSet(u) != findSet(v)) {
                unionSets(u, v);
                // Rebuild subtree sizes
                for (int i = 1; i <= n; ++i) {
                    buildSubtreeSizes(i, -1);
                }
            }
        } else if (type == 2) {
            // Find k-th largest vertex
            int root = findSet(v);
            if (subtreeSizes[root] < k) {
                cout << -1 << '\n';
            } else {
                vector<int> sortedVertices(adjList[root].size());
                for (int i = 0; i < adjList[root].size(); ++i) {
                    sortedVertices[i] = adjList[root][i];
                }
                sort(sortedVertices.begin(), sortedVertices.end(), greater<int>());

                cout << sortedVertices[k - 1] << '\n';
            }
        }
    }

    return 0;
}