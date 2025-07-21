#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 9;

vector<int> parents(N);
vector<set<int>> graph(N);

int find(int u) {
    if (parents[u] != u) {
        parents[u] = find(parents[u]);
    }
    return parents[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parents[v] = u;
        merge(graph[u].begin(), graph[u].end(), graph[v].begin(), graph[v].end());
    }
}

int kthLargest(int v, int k) {
    v = find(v);
    if (graph[v].size() < k) {
        return -1;
    }
    auto it = graph[v].upper_bound(-N);
    return -(*it);
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionSets(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << kthLargest(v, k) << endl;
        }
    }

    return 0;
}