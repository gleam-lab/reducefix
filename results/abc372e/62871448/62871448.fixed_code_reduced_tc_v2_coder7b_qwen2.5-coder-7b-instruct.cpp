#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
set<int> st[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    st[u].insert(v);
    st[v].insert(u);
}

int kthLargest(int v, int k) {
    if (st[v].size() < k) return -1;
    auto it = st[v].rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else {
            cin >> u >> k;
            cout << kthLargest(u, k) << '\n';
        }
    }

    return 0;
}