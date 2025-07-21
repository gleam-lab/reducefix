#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int v) {
    pq[v].push(-v);
    while(pq[v].size() > 10) pq[v].pop();
}

int kthLargest(int v, int k) {
    if(k > pq[v].size()) return -1;
    priority_queue<int, vector<int>, greater<int>> temp = pq[v];
    for(int i = 0; i < k - 1; ++i) temp.pop();
    return -temp.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; ++i) {
        updatePQ(i);
    }

    while(q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) {
            addEdge(u, v);
            updatePQ(u);
            updatePQ(v);
        } else {
            cout << kthLargest(u, v) << "\n";
        }
    }

    return 0;
}