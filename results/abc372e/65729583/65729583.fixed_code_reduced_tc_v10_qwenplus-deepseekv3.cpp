#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
    if(V[u].size() < V[v].size()) swap(u, v);
    U[v] = u;
    for(auto num : V[v]) {
        V[u].insert(num);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        U[i] = i;
        V[i].insert(i);
    }

    int cmd, u, v, k;
    while(q--) {
        cin >> cmd;
        if(cmd == 1) {
            cin >> u >> v;
            Union(u, v);
        } else {
            cin >> u >> k;
            u = Find(u);
            if((int)V[u].size() < k) {
                cout << -1 << endl;
            } else {
                cout << *V[u].find_by_order(V[u].size() - k) << endl;
            }
        }
    }
    return 0;
}