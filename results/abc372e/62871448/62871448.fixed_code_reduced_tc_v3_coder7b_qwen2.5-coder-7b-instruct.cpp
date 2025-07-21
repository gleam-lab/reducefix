#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
set<int> st[MAXN];

void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    st[u].insert(v);
    st[v].insert(u);
}

int find_kth_largest(set<int>& s, int k){
    auto it = s.rbegin();
    advance(it, k-1);
    return *it;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while(m--){
        int type;
        cin >> type;

        if(type == 1){
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            if(st[v].size() < k){
                cout << "-1" << endl;
            } else {
                cout << find_kth_largest(st[v], k) << endl;
            }
        }
    }

    return 0;
}