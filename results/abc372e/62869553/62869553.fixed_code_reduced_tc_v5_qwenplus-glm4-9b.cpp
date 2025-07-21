#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
int parent[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rootX < rootY)
            parent[rootY] = rootX;
        else
            parent[rootX] = rootY;
    }
}

bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> connectedVertices;
    vector<int> sizes[MAXN];

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            // Union two sets
            unionSets(u, v);
        } else if (op == 2) {
            // Find the connected components
            int rootV = find(v);
            vector<int> components;
            for (int i = 1; i <= n; ++i) {
                if (find(i) == rootV) {
                    components.push_back(i);
                }
            }
            sort(components.rbegin(), components.rend());
            if (k <= components.size()) {
                cout << components[k - 1] << endl;
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}