#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int degree[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
}

int findKthLargest(int v, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int neighbor : adj[v]) {
        pq.push(neighbor);
        if (pq.size() > k) pq.pop();
    }
    return pq.size() == k ? pq.top() : -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int type, v, k;
        cin >> type >> v;
        if (type == 1) {
            int u;
            cin >> u;
            addEdge(u, v);
        } else {
            cin >> k;
            cout << findKthLargest(v, k) << endl;
        }
    }
    return 0;
}