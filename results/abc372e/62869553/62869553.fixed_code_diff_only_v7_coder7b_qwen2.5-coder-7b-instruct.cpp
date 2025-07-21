#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq[u].push(v);
    pq[v].push(u);
}

void queryKthLargest(int v, int k) {
    if (pq[v].size() < k) {
        cout << "-1" << endl;
        return;
    }
    while (k > 1 && !pq[v].empty()) {
        pq[v].pop();
        k--;
    }
    cout << pq[v].top() << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            cin >> u >> k;
            queryKthLargest(u, k);
        }
    }

    return 0;
}