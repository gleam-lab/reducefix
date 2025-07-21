#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<multiset<int>> adj;

void addEdge(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

int kthLargest(int v, int k) {
    auto it = adj[v].rbegin();
    advance(it, k - 1);
    return *it;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    adj.resize(n + 1);

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            addEdge(a, b);
        } else {
            if(adj[a].size() < k) {
                cout << "-1\n";
            } else {
                cout << kthLargest(a, k) << '\n';
            }
        }
    }

    return 0;
}