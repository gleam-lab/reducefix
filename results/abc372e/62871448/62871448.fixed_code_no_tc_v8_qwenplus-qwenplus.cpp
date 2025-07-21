#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int TOP_K = 10;

int parent[MAXN];
set<int, greater<int>> roots[MAXN];  // Store top 10 largest vertices in each DSU root

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb)
        return;

    // Always merge smaller set into larger set for better performance
    if (roots[ra].size() < roots[rb].size())
        swap(ra, rb);

    // Merge the two sets
    for (int val : roots[rb])
        roots[ra].insert(val);

    // Keep only top 10 largest values
    while (roots[ra].size() > TOP_K) {
        auto it = roots[ra].end();
        --it;
        roots[ra].erase(it);
    }

    parent[rb] = ra;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and sets
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        roots[i].insert(i);
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        } else if (op == 2) {
            int v, k;
            cin >> v >> k;
            
            int root = find(v);
            if (roots[root].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = roots[root].begin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}