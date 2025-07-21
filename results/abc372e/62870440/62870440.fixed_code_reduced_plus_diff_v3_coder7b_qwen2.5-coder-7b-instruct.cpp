#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) addEdge(i, i);

    for(int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if(type == 1) {
            addEdge(u, v);
            updatePQ(u);
            updatePQ(v);
        } else {
            if(adj[u].size() < v) cout << "-1\n";
            else {
                auto it = pq[u].begin();
                advance(it, v - 1);
                cout << -(*it) << "\n";
            }
        }
    }

    return 0;
}