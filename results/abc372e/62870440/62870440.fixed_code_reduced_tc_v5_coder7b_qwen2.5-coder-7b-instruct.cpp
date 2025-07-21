#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
set<int> st[MAXN];

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    st[u].insert(v);
    st[v].insert(u);
}

void remove_edge(int u, int v) {
    adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
    adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
    st[u].erase(st[u].find(v));
    st[v].erase(st[v].find(u));
}

int get_kth_largest(int u, int k) {
    if(k > st[u].size()) return -1;
    auto it = st[u].rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    while(q--) {
        int type, u, v, k;
        cin >> type;
        if(type == 1) {
            cin >> u >> v;
            add_edge(u, v);
        } else {
            cin >> u >> k;
            cout << get_kth_largest(u, k) << '\n';
        }
    }
    return 0;
}