#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> adj[MAXN];
set<int> st[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    st[u].insert(v);
    st[v].insert(u);
}

void mergeSets(int u, int v) {
    if (st[u].size() > st[v].size()) swap(u, v);
    for (int x : st[u]) {
        st[v].insert(x);
        adj[v].push_back(x);
        adj[x].push_back(v);
    }
    st[u].clear();
}

int findKthLargest(int u, int k) {
    return *(next(st[u].rbegin(), k - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    while (q--) {
        int op, ix, iy;
        cin >> op >> ix >> iy;

        if (op == 1) {
            addEdge(ix, iy);
        } else {
            if (st[ix].size() >= iy) {
                cout << findKthLargest(ix, iy) << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}