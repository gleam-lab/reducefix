#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
set<int> s[MAXN];

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    s[u].insert(v);
    s[v].insert(u);
}

int find_kth_largest(int v, int k) {
    if(k > s[v].size()) return -1;
    auto it = s[v].rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
            cout << find_kth_largest(u, k) << "\n";
        }
    }

    return 0;
}