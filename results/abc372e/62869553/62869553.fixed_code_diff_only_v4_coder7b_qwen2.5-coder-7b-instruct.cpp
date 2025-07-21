#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(-v);
    pq[v].push(-u);
}

int findKthLargest(int v, int k) {
    while (!pq[v].empty() && k > 0) {
        if (k == 1) return -pq[v].top();
        pq[v].pop();
        k--;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            cout << findKthLargest(v, k) << "\n";
        }
    }

    return 0;
}