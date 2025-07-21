#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 2e5 + 9;

vector<int> parent(N);
vector<int> size(N);
map<int, vector<int>> componentVertices;

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u != v) {
        if (size[u] < size[v]) {
            swap(u, v);
        }
        size[u] += size[v];
        parent[v] = u;
        componentVertices[u].insert(componentVertices[u].end(), componentVertices[v].begin(), componentVertices[v].end());
        componentVertices.erase(v);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    parent.fill(-1);
    size.fill(0);
    componentVertices.clear();

    for (int i = 1; i <= n; ++i) {
        componentVertices[i].push_back(i);
    }

    while (q--) {
        int cmd, u, v;
        cin >> cmd;
        if (cmd == 1) {
            cin >> u >> v;
            unionSets(u, v);
        } else {
            cin >> v >> u;
            v = findSet(v);
            if (componentVertices[v].size() < u) {
                cout << -1 << endl;
            } else {
                cout << componentVertices[v][componentVertices[v].size() - u] << endl;
            }
        }
    }

    return 0;
}