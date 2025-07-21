#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 2 * 100000 + 5;

vector<int> parent(MAX_N);
vector<set<int>> adjList(MAX_N);

int findParent(int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node]);
    }
    return parent[node];
}

void unionSets(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    
    if (pu == pv) return;
    
    // Merge smaller set into larger set
    if (adjList[pu].size() > adjList[pv].size()) {
        swap(pu, pv);
    }
    
    for (auto &neighbor : adjList[pu]) {
        adjList[pv].insert(neighbor);
    }
    adjList[pu].clear();
    parent[pu] = pv;
}

int kthLargest(int u, int k) {
    int pu = findParent(u);
    auto it = adjList[pu].rbegin();
    advance(it, k - 1);
    if (it != adjList[pu].rend()) {
        return *it;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        adjList[i].insert(i);
    }

    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            unionSets(u, v);
        } else {
            int result = kthLargest(v, k);
            cout << result << '\n';
        }
    }

    return 0;
}