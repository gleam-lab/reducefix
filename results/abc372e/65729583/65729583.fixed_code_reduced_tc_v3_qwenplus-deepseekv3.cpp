#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 2e5 + 9;
int U[N];
ordered_set V[N];

int Find(int u) {
    if(U[u] == u) return u;
    return U[u] = Find(U[u]);
}

void Union(int u, int v) {
    u = Find(u); v = Find(v);
    if(u == v) return;
    
    if(V[v].size() > V[u].size()) swap(V[u], V[v]);
    U[v] = u;
    
    for(int num : V[v]) {
        V[u].insert(num);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        U[i] = i;
        V[i].insert(i);
    }

    while(q--) {
        int cmd;
        cin >> cmd;
        
        if(cmd == 1) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = Find(v);
            
            if((int)V[v].size() < k) {
                cout << -1 << '\n';
            } else {
                int sz = V[v].size();
                auto it = V[v].find_by_order(sz - k);
                cout << *it << '\n';
            }
        }
    }
    
    return 0;
}