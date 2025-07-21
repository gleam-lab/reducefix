#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
int size[MAXN];
map<int, vector<int>> componentMembers;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Always merge smaller set into larger one
    if ((int)componentMembers[fx].size() < (int)componentMembers[fy].size()) {
        swap(fx, fy);
    }

    // Merge fy's elements into fx
    for (int node : componentMembers[fy]) {
        componentMembers[fx].push_back(node);
    }
    sort(componentMembers[fx].rbegin(), componentMembers[fx].rend());

    parent[fy] = fx;
    componentMembers.erase(fy); // Remove the old component
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and component members
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
        componentMembers[i] = {i};
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
            const vector<int>& members = componentMembers[root];
            if ((int)members.size() < k) {
                cout << -1 << '\n';
            } else {
                cout << members[k - 1] << '\n';
            }
        }
    }

    return 0;
}