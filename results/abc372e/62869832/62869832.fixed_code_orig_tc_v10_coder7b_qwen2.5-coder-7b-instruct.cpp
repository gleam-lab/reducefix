#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int, vector<int>, greater<int>> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePriorityQueue(int u, int v) {
    if(find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) {
        pq[u].push(v);
        while(pq[u].size() > 10) pq[u].pop();
    }
}

void removeElementFromPQ(int u, int v) {
    auto it = find(pq[u].begin(), pq[u].end(), v);
    if(it != pq[u].end()) pq[u].erase(it);
}

int getKthLargest(int u, int k) {
    if(k > pq[u].size()) return -1;
    else return pq[u].top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        pq[i].push(-1);
    }

    for(int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if(type == 1) {
            addEdge(u, v);
            updatePriorityQueue(u, v);
            updatePriorityQueue(v, u);
        } else {
            cout << getKthLargest(u, v) << '\n';
        }
    }

    return 0;
}