#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    if(pq[u].size() > 10) pq[u].pop();
    pq[v].push(u);
    if(pq[v].size() > 10) pq[v].pop();
}

int getKthLargest(int v, int k) {
    if(k > pq[v].size()) return -1;
    priority_queue<int, vector<int>, greater<int>> temp = pq[v];
    for(int i = 1; i <= k - 1; ++i) temp.pop();
    return temp.top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= q; ++i) {
        int type;
        cin >> type;
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << getKthLargest(v, k) << '\n';
        }
    }
    return 0;
}