#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
priority_queue<int> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(-v);
    pq[v].push(-u);
}

void getKthLargest(int v, int k) {
    if (pq[v].size() < k) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < k - 1; ++i) {
        pq[v].pop();
    }
    cout << -pq[v].top() << "\n";
}

int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            addEdge(u, v);
        } else {
            getKthLargest(u, v);
        }
    }
    return 0;
}