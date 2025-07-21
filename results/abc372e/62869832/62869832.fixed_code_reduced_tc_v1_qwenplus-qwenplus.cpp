#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
vector<int> members[MAXN];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;

    // Always merge smaller set into larger one
    if (members[rootX].size() < members[rootY].size())
        swap(rootX, rootY);

    // Merge members of Y into X
    members[rootX].insert(members[rootX].end(), members[rootY].begin(), members[rootY].end());
    sort(members[rootX].rbegin(), members[rootX].rend());

    // Limit member list size to top 10 for optimization
    if (members[rootX].size() > 10)
        members[rootX].resize(10);

    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and member lists
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        members[i].push_back(i);
    }

    for (int i = 0; i < Q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (members[root].size() >= k)
                cout << members[root][k - 1] << "\n";
            else
                cout << "-1\n";
        }
    }

    return 0;
}