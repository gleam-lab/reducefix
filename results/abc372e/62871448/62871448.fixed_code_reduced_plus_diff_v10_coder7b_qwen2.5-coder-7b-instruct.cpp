#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 10;
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent) {
    for(auto child : adj[node]) {
        if(child != parent) {
            dfs(child, node);
            while(!pq[child].empty() && pq[node].size() < 10) {
                pq[node].push(pq[child].top());
                pq[child].pop();
            }
        }
    }
}

int kthLargest(int node, int k) {
    if(k > pq[node].size()) return -1;
    auto temp = pq[node];
    nth_element(temp.begin(), temp.begin()+k-1, temp.end());
    return temp[k-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        pq[i].push(i);
    }

    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    dfs(1, -1);

    for(int i = 0; i < q; ++i) {
        int type, v, k;
        cin >> type >> v >> k;
        if(type == 1) {
            cout << "1" << endl;
        } else {
            cout << kthLargest(v, k) << endl;
        }
    }

    return 0;
}