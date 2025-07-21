#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
const int MAXK = 10;

vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void processQueries(int n, int q) {
    for (int i = 0; i < q; ++i) {
        int type, v, k;
        cin >> type >> v;
        if (type == 1) {
            int u;
            cin >> u;
            addEdge(v, u);
            for (int w : adj[u]) {
                pq[w].push(v);
                if (pq[w].size() > MAXK) pq[w].pop();
            }
        } else {
            cin >> k;
            if (pq[v].size() >= k) cout << pq[v].top() << "\n";
            else cout << "-1\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    processQueries(n, q);

    return 0;
}