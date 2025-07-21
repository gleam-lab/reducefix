#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 200000 + 1;

vector<int> parents(N);
vector<vector<int>> children(N);

void findParent(int u) {
    if (parents[u] == u)
        return;
    findParent(parents[u]);
    parents[u] = parents[parents[u]];
}

void addEdge(int u, int v) {
    findParent(u);
    findParent(v);
    if (u != v) {
        children[parents[u]].push_back(v);
        children[parents[v]].push_back(u);
    }
}

vector<int> getConnectedVertices(int v) {
    vector<int> result;
    findParent(v);
    for (int child : children[parents[v]])
        result.push_back(child);
    return result;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        parents[i] = i;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            vector<int> connected = getConnectedVertices(v);
            if (k > connected.size()) {
                cout << -1 << endl;
            } else {
                cout << connected[connected.size() - k] << endl;
            }
        }
    }
    return 0;
}