#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
    if (pq[u].size() > 10) pq[u].pop();
    if (pq[v].size() > 10) pq[v].pop();
}

int getKthLargest(int v, int k) {
    if (pq[v].size() < k) return -1;
    priority_queue<int, vector<int>, greater<int>> temp = pq[v];
    for (int i = 1; i < k; ++i) {
        temp.pop();
    }
    return temp.top();
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << getKthLargest(v, k) << endl;
        }
    }
    return 0;
}