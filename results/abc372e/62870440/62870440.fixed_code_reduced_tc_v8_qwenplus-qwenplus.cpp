#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
set<int> components[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    
    // Merge smaller set into larger one to keep tree depth small
    if (components[fx].size() < components[fy].size()) {
        swap(fx, fy);
    }
    
    for (int node : components[fy]) {
        components[fx].insert(node);
    }
    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if ((int)components[root].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = components[root].rbegin(); // reverse iterator for descending order
                for (int i = 1; i < k && it != components[root].rend(); ++i) {
                    ++it;
                }
                if (it == components[root].rend()) {
                    cout << -1 << "\n";
                } else {
                    cout << *it << "\n";
                }
            }
        }
    }

    return 0;
}