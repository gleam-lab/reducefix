#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> adj[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void updateQueue(int u, int v) {
    pq[u].emplace(-v, v);
    pq[v].emplace(-u, u);
}

int kthLargest(int u, int k) {
    while (!pq[u].empty() && pq[u].top().second != u) {
        pq[u].pop();
    }
    if (pq[u].size() < k) return -1;
    return -pq[u].nth_element(k-1)->second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < q; ++i) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            addEdge(u, v);
            updateQueue(u, v);
        } else {
            cin >> u >> k;
            cout << kthLargest(u, k) << '\n';
        }
    }
    
    return 0;
}