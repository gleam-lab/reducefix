#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int u) {
    pq[u].clear();
    for(auto &v : adj[u]) pq[u].push(v);
}

int getKthLargest(int u, int k) {
    if(k > pq[u].size()) return -1;
    priority_queue<int, vector<int>, greater<int>> temp(pq[u]);
    while(--k) temp.pop();
    return temp.top();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if(type == 1) {
            addEdge(u, v);
            updatePQ(u);
            updatePQ(v);
        } else {
            cout << getKthLargest(u, k) << '\n';
        }
    }

    return 0;
}