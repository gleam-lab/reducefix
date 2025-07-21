#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updatePQ(int v) {
    pq[v].push(-v);
    while(pq[v].size() > 10) pq[v].pop();
}

void solveQueries(int n, int q) {
    for(int i = 1; i <= n; ++i) {
        updatePQ(i);
    }
    
    while(q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if(type == 1) {
            int u;
            cin >> u;
            addEdge(u, v);
            updatePQ(u);
            updatePQ(v);
        } else {
            if(pq[v].size() < k) cout << "-1\n";
            else cout << -pq[v].nth(k - 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    solveQueries(n, q);

    return 0;
}