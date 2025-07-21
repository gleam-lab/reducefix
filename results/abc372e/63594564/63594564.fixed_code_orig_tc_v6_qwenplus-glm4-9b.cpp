#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> parent(MAXN, -1);
vector<vector<int>> graph(MAXN);
vector<vector<int>> vertices(MAXN);  // to store sorted vertices in the component

int find(int x) {
    if (parent[x] == -1) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (vertices[x].size() < vertices[y].size()) {
            swap(x, y);
        }
        for (int u : vertices[y]) {
            graph[x].push_back(u);
        }
        vertices[x].insert(vertices[x].end(), vertices[y].begin(), vertices[y].end());
        vertices[y].clear();
        parent[y] = x;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        vertices[i].push_back(i);
    }
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            unionSets(u, v);
        } else if (type == 2) {
            int p = find(v);
            if (vertices[p].size() < v) {
                cout << -1 << '\n';
            } else {
                sort(vertices[p].rbegin(), vertices[p].rend());
                cout << vertices[p][v - 1] << '\n';
            }
        }
    }
    return 0;
}