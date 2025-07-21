#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
vector<int> top_members[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return;

    // Always merge smaller into larger
    if (top_members[rootX].size() < top_members[rootY].size())
        swap(rootX, rootY);

    // Merge members of rootY into rootX
    for (int v : top_members[rootY]) {
        top_members[rootX].push_back(v);
    }

    // Sort and retain only top K_MAX elements
    sort(top_members[rootX].begin(), top_members[rootX].end(), greater<int>());
    if (top_members[rootX].size() > K_MAX)
        top_members[rootX].resize(K_MAX);

    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_members[i].push_back(i);
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (op == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (k <= (int)top_members[root].size())
                cout << top_members[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}