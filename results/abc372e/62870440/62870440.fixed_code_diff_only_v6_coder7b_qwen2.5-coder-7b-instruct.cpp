#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
priority_queue<int> pq[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void processQueries(int q, int n) {
    for (int i = 0; i < q; ++i) {
        int type, v, k;
        cin >> type >> v;
        if (type == 1) {
            cin >> k;
            addEdge(v, k);
        } else if (type == 2) {
            cin >> k;
            if (adj[v].size() < k) {
                cout << -1 << "\n";
            } else {
                pq[v].push(-v); // Using negative value for max heap simulation
                while (pq[v].size() > k) {
                    pq[v].pop();
                }
                cout << -pq[v].top() << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    processQueries(q, n);

    return 0;
}