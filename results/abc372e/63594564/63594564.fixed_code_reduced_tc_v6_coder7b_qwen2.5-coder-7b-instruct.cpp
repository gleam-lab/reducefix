#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()
#define vi vector<int>
#define pb push_back

const int N = 2e5 + 5;

vi adj[N];
priority_queue<int, vi, greater<>> pq[N];

void addEdge(int u, int v) {
    adj[u].pb(v);
    adj[v].pb(u);
    pq[u].push(v);
    pq[v].push(u);
    if(pq[u].size() > 10) pq[u].pop();
    if(pq[v].size() > 10) pq[v].pop();
}

int kthLargest(int v, int k) {
    if(adj[v].size() < k) return -1;
    priority_queue<int, vi, greater<>> temp = pq[v];
    for(int i = 1; i < k; ++i) temp.pop();
    return temp.top();
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
        } else {
            cout << kthLargest(a, b) << '\n';
        }
    }
    
    return 0;
}