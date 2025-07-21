#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int parent[MAXN];
vector<int> top10[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v)
        return;

    // Merge smaller into larger
    if (top10[root_u].size() < top10[root_v].size())
        swap(root_u, root_v);

    // Merge top10 lists
    vector<int> merged;
    int i = 0, j = 0;
    while (i < (int)top10[root_u].size() && j < (int)top10[root_v].size() && merged.size() < K) {
        if (top10[root_u][i] > top10[root_v][j])
            merged.push_back(top10[root_u][i++]);
        else
            merged.push_back(top10[root_v][j++]);
    }

    while (i < (int)top10[root_u].size() && merged.size() < K)
        merged.push_back(top10[root_u][i++]);

    while (j < (int)top10[root_v].size() && merged.size() < K)
        merged.push_back(top10[root_v][j++]);

    // Replace top10 of root_u with merged result
    top10[root_u] = merged;
    parent[root_v] = root_u;
    top10[root_v].clear(); // Optional cleanup
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top10[i] = {i};
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if ((int)top10[root].size() < k)
                cout << -1 << "\n";
            else
                cout << top10[root][k - 1] << "\n";
        }
    }

    return 0;
}