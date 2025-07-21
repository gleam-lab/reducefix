#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <vector <int>> adj(N);
vector <int> degree(N);
vector <priority_queue<int,vector<int>,greater<int>>> pq(N);

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
}

void processQueries(vector<pair<int,int>>& queries) {
    for(auto& [t, v]: queries) {
        if(t == 2) {
            if(degree[v] < 10) {
                cout << "-1\n";
            } else {
                auto it = pq[v].begin();
                advance(it,degree[v]-10);
                cout << *it << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i].ff >> queries[i].ss;
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    for(int i = 1; i <= n; i++) {
        for(auto &v: adj[i]) {
            pq[i].push(v);
            if(pq[i].size() > 10) pq[i].pop();
        }
    }

    processQueries(queries);

    return 0;
}