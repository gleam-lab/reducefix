#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int N, Q;
int parent[MAXN];
vector<int> top[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
        return;

    // Always merge smaller into larger
    if (top[pu].size() < top[pv].size())
        swap(pu, pv);

    // Merge top-K lists
    vector<int> merged;
    int i = 0, j = 0;
    while (i < top[pu].size() && j < top[pv].size() && merged.size() < K) {
        if (top[pu][i] > top[pv][j])
            merged.push_back(top[pu][i++]);
        else
            merged.push_back(top[pv][j++]);
    }

    while (i < top[pu].size() && merged.size() < K)
        merged.push_back(top[pu][i++]);

    while (j < top[pv].size() && merged.size() < K)
        merged.push_back(top[pv][j++]);

    // Update parent
    parent[pv] = pu;
    top[pu] = merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i] = {i};
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
            int p = find(v);
            if (k <= top[p].size())
                cout << top[p][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}