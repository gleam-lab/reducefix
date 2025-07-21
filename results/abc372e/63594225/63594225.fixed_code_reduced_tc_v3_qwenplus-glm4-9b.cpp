#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 2e5 + 5;

vector<int> adjacencyList(N);
vector<int> size(N);
vector<int> parent(N);

void initialize(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        size[i] = 0;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (size[u] < size[v]) {
        swap(u, v);
    }
    parent[v] = u;
    size[u] += size[v];
    adjacencyList[u].insert(adjacencyList[u].end(), adjacencyList[v].begin(), adjacencyList[v].end());
}

int main() {
    int n, q;
    cin >> n >> q;
    initialize(n);

    int u, v, k;
    for (int i = 0; i < q; i++) {
        cin >> k >> (k == 1 ? u : v) >> (k == 1 ? v : u);
        if (k == 1) {
            unionSets(u, v);
        } else {
            v = find(v);
            if (size[v] < v) {
                cout << -1 << '\n';
            } else {
                set<int> connectedVertices(adjacencyList[v].begin(), adjacencyList[v].end());
                auto it = connectedVertices.rbegin();
                advance(it, v - 1); // Move to the v-th largest element
                cout << *it << '\n';
            }
        }
    }

    return 0;
}