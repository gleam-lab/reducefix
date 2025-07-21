#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
}

void getKthLargest(int v, int k) {
    if (pq[v].size() < k) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < k - 1; ++i) {
            pq[v].pop();
        }
        cout << pq[v].top() << endl;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    while(q--) {
        int type, v, k;
        cin >> type >> v;
        if(type == 1) {
            cin >> k;
            addEdge(v, k);
        } else if(type == 2) {
            cin >> k;
            getKthLargest(v, k);
        }
    }
    return 0;
}