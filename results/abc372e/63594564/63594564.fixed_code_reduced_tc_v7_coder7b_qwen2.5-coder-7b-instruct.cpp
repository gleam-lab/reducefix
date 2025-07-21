#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> adj[N];
priority_queue<int> pq[N];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(-v);
    pq[v].push(-u);
}

void findKthLargest(int v, int k) {
    int cnt = 0;
    while(!pq[v].empty()) {
        int top = -pq[v].top();
        pq[v].pop();
        cnt++;
        if(cnt == k) {
            cout << top << '\n';
            return;
        }
    }
    cout << "-1\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            addEdge(u, v);
        } else {
            findKthLargest(u, v);
        }
    }
    
    return 0;
}