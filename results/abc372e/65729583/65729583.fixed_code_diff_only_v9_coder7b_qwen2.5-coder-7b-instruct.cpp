#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 9;

vector<vector<int>> graph(MAXN);
vector<set<int>> adjSet(MAXN);

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    adjSet[u].insert(v);
    adjSet[v].insert(u);
}

int find(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent) {
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (pu != pv) {
        if (adjSet[pu].size() < adjSet[pv].size()) {
            swap(pu, pv);
        }
        for (int neighbor : adjSet[pv]) {
            adjSet[pu].insert(neighbor);
            if (adjSet[pu].size() > 10) break;
        }
        parent[pv] = pu;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
            unionSets(u, v, parent);
        } else {
            cin >> u >> k;
            u = find(u, parent);
            if (adjSet[u].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = adjSet[u].rbegin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}