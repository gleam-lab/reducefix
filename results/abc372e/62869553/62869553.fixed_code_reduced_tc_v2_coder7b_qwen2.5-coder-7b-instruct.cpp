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

int getKthLargest(int u, int k) {
    while(k--) {
        if(pq[u].size() > 0) {
            int top = pq[u].top();
            pq[u].pop();
            return top;
        }
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if(type == 1) {
            addEdge(u, v);
        } else {
            cout << getKthLargest(u, v - 1) << endl;
        }
    }

    return 0;
}