#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int node, int new_val) {
    pq[node].push(new_val);
    while(pq[node].size() > 10) pq[node].pop();
}

int getKthLargest(int node, int k) {
    if(k > pq[node].size()) return -1;
    priority_queue<int, vector<int>, greater<int>> temp = pq[node];
    for(int i = 0; i < k - 1; ++i) temp.pop();
    return temp.top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int type, u, v, k;
        cin >> type;
        if(type == 1) {
            cin >> u >> v;
            addEdge(u, v);
            updatePQ(u, v);
            updatePQ(v, u);
        } else {
            cin >> u >> k;
            cout << getKthLargest(u, k) << '\n';
        }
    }
    return 0;
}