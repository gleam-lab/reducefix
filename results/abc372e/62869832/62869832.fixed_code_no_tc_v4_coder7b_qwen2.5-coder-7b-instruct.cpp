#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
}

int kthLargest(int v, int k) {
    if (pq[v].size() < k) return -1;
    while (--k > 0) pq[v].pop();
    int result = pq[v].top();
    pq[v].push(result); // Push it back to maintain the heap property
    return result;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < q; ++i) {
        int type, v, k;
        cin >> type >> v;
        
        if (type == 1) {
            cin >> k;
            addEdge(v, k);
        } else {
            cout << kthLargest(v, 10) << endl;
        }
    }
    
    return 0;
}