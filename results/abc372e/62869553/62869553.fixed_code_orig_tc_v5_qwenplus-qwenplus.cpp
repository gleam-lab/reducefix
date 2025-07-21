#include <bits/stdc++.h>
using namespace std;

const int K = 10;
const int MAXN = 2 * 100000 + 5;

int parent[MAXN];
vector<int> topk[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return;

    // Always merge smaller into larger for better performance
    if (topk[xr].size() < topk[yr].size())
        swap(xr, yr);

    // Merge top-k lists
    vector<int> merged;
    int i = 0, j = 0;
    while (i < topk[xr].size() && j < topk[yr].size()) {
        if (topk[xr][i] > topk[yr][j])
            merged.push_back(topk[xr][i++]);
        else
            merged.push_back(topk[yr][j++]);
        if (merged.size() == K)
            break;
    }

    while (i < topk[xr].size() && merged.size() < K)
        merged.push_back(topk[xr][i++]);
    while (j < topk[yr].size() && merged.size() < K)
        merged.push_back(topk[yr][j++]);

    // Update smaller root's data to merged list
    parent[yr] = xr;
    topk[xr] = merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and top-k arrays
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topk[i] = {i};
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
            int r = find(v);
            if (topk[r].size() < k)
                cout << -1 << '\n';
            else
                cout << topk[r][k - 1] << '\n';
        }
    }

    return 0;
}