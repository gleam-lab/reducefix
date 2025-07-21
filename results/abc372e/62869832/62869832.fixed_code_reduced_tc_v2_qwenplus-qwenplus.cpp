#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int TOP_LIMIT = 10;

int N, Q;
int parent[MAXN];
vector<int> tops[MAXN];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets: small-to-large technique
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Always merge smaller into larger
    if (tops[fx].size() < tops[fy].size()) swap(fx, fy);

    // Merge the top lists
    vector<int> merged;
    merged.reserve(tops[fx].size() + tops[fy].size());
    merged.insert(merged.end(), tops[fx].begin(), tops[fx].end());
    merged.insert(merged.end(), tops[fy].begin(), tops[fy].end());

    // Sort and keep only top 10
    sort(merged.begin(), merged.end(), greater<int>());
    merged.resize(min((int)merged.size(), TOP_LIMIT));
    tops[fx] = merged;
    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        tops[i] = {i};
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
            if (k <= (int)tops[root].size())
                cout << tops[root][k - 1] << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}