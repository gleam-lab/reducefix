#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_LIMIT = 10;

int parent[MAXN];
set<int, greater<int>> group[MAXN]; // Store top K elements in descending order

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets ensuring only the root nodes are passed
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    
    if (fx == fy) return;
    
    // Always merge smaller set into larger one
    if (group[fx].size() < group[fy].size()) {
        swap(fx, fy);
        swap(group[fx], group[fy]);
    }
    
    // Merge the two groups
    for (auto it = group[fy].begin(); it != group[fy].end(); ++it) {
        group[fx].insert(*it);
        if (group[fx].size() > K_LIMIT) {
            group[fx].erase(--group[fx].end());
        }
    }
    
    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        group[i].insert(i);
    }

    while (Q--) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            unite(u, v);
        } else if (type == 2) {
            int fv = find(u);
            if (group[fv].size() < v) {
                cout << -1 << '\n';
            } else {
                auto it = group[fv].begin();
                advance(it, v - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}