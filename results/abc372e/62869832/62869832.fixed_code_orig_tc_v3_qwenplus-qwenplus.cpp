#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int TOP_K = 10;

int parent[MAXN];
vector<int> tops[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;

    // Always merge smaller into larger for efficiency
    if (tops[pu].size() < tops[pv].size())
        swap(pu, pv);

    // Merge the lists
    vector<int> merged;
    auto& a = tops[pu];
    auto& b = tops[pv];

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j])
            merged.push_back(a[i++]);
        else
            merged.push_back(b[j++]);
    }
    while (i < a.size() && merged.size() < TOP_K)
        merged.push_back(a[i++]);
    while (j < b.size() && merged.size() < TOP_K)
        merged.push_back(b[j++]);

    tops[pu] = merged;
    parent[pv] = pu;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and tops
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
            if (tops[root].size() < k)
                cout << -1 << '\n';
            else
                cout << tops[root][k - 1] << '\n';
        }
    }

    return 0;
}