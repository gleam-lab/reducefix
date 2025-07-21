#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> adj[N];
priority_queue<int, vector<int>, greater<int>> pq[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
}

int kthLargest(int u, int k) {
    while (pq[u].size() > k) pq[u].pop();
    return pq[u].size() >= k ? pq[u].top() : -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            addEdge(u, v);
        } else {
            cout << kthLargest(u, k) << '\n';
        }
    }

    return 0;
}