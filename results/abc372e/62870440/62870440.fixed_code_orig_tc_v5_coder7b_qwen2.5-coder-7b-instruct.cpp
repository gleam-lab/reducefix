#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF 1e9

vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void processQueries(int n, int q) {
    for(int i = 0; i < q; i++) {
        int type, u, v, k;
        cin >> type;
        if(type == 1) {
            cin >> u >> v;
            addEdge(u, v);
            for(auto x : adj[v]) {
                pq[x].push(u);
                if(pq[x].size() > 10) pq[x].pop();
            }
            for(auto x : adj[u]) {
                pq[x].push(v);
                if(pq[x].size() > 10) pq[x].pop();
            }
        } else {
            cin >> u >> k;
            if(pq[u].size() < k) cout << "-1" << endl;
            else {
                while(k--) {
                    cout << pq[u].top() << " ";
                    pq[u].pop();
                }
                cout << endl;
                for(auto x : adj[u]) pq[x].push(u);
                for(auto x : adj[v]) pq[x].push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    processQueries(n, q);
    return 0;
}