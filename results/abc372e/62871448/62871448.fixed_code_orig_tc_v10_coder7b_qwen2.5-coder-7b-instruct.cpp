#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int u, int v, bool added) {
    if(added) pq[u].push(v), pq[v].push(u);
    else pq[u].erase(find(pq[u].begin(), pq[u].end(), v)), pq[v].erase(find(pq[v].begin(), pq[v].end(), u));
}

int getKthLargest(int u, int k) {
    while(k && !pq[u].empty()) {
        auto top = pq[u].top();
        pq[u].pop();
        if(top == -1) continue;
        pq[u].push(-1);
        return top;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) pq[i].push(-1);

    for(int i = 0; i < q; ++i) {
        int t, u, v; cin >> t;
        if(t == 1) {
            cin >> u >> v;
            addEdge(u, v);
            updatePQ(u, v, true);
        } else {
            cin >> u >> v;
            cout << getKthLargest(u, v) << '\n';
        }
    }

    return 0;
}