#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
vector<int> top_values[MAXN]; // Stores up to 10 largest values in the component

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets: always attach smaller rank to bigger rank
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Attach smaller tree to larger tree
    parent[fy] = fx;
    // Merge the top values
    vector<int> merged;
    merged.insert(merged.end(), top_values[fx].begin(), top_values[fx].end());
    merged.insert(merged.end(), top_values[fy].begin(), top_values[fy].end());

    // Sort in descending order and keep top 10
    sort(merged.rbegin(), merged.rend());
    merged.resize(min(10, (int)merged.size()));
    top_values[fx] = merged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_values[i] = {i};
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
            if ((int)top_values[root].size() < k)
                cout << -1 << '\n';
            else
                cout << top_values[root][k - 1] << '\n';
        }
    }

    return 0;
}