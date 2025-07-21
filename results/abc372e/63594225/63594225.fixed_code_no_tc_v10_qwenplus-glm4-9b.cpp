#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
vector<int> ans;
priority_queue<int> pq;
vector<int> size(N, 1);

void merge(int u, int v) {
    if (size[u] < size[v]) swap(u, v);
    size[u] += size[v];
    g[u].insert(g[u].end(), g[v].begin(), g[v].end());
}

int findKthLargest(int v, int k) {
    auto it = upper_bound(g[v].rbegin(), g[v].rend(), -k);
    return g[v].rend() - it;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            merge(u, v);
        } else if (t == 2) {
            ans.push_back(findKthLargest(v, k));
        }
    }
    for (int &a : ans) {
        cout << a << '\n';
    }
    return 0;
}