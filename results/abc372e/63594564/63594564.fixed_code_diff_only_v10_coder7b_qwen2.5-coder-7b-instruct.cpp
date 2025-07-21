#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <set<int>> adj[N];

void addEdge(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

void removeEdge(int u, int v) {
    adj[u].erase(v);
    adj[v].erase(u);
}

int getKthLargest(int v, int k) {
    if(adj[v].size() < k) return -1;
    auto it = adj[v].rbegin();
    advance(it, k-1);
    return *it;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            addEdge(a, b);
        }
        else {
            cout << getKthLargest(a, b) << '\n';
        }
    }

    return 0;
}