#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> adj[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int findKthLargest(vector<int>& vec, int k) {
    sort(vec.begin(), vec.end(), greater<int>());
    if (k > vec.size()) return -1;
    return vec[k - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> pq(n + 1);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
            // Update priority queues for both nodes
            pq[u].push_back(v);
            pq[v].push_back(u);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            cout << findKthLargest(pq[v], k) << '\n';
        }
    }

    return 0;
}