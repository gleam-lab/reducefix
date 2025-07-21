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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            
            auto it = st[v].rbegin();
            if(k > distance(st[v].begin(), it)) {
                cout << "-1\n";
            } else {
                cout << *next(it, k-1) << "\n";
            }
        }
    }
    
    return 0;
}