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

#define all(v) v.begin(),v.end() 
#define rall(v) v.rbegin(),v.rend()

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef pair<ii,ii> iiii;

typedef int typeOfData;
typedef tree<typeOfData, null_type, less<typeOfData>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
    
    for(auto num : V[v]) {
        V[u].insert(num);
    }
    U[v] = u;
}

void solve() {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        U[i] = i;
        V[i].insert(i);
    }

    while(q--) {
        int cmd; cin >> cmd;
        if(cmd == 1) {
            int u, v; cin >> u >> v;
            Union(u, v);
        } else {
            int v, k; cin >> v >> k;
            v = Find(v);
            if(V[v].size() < k) {
                cout << -1 << '\n';
            } else {
                cout << *V[v].find_by_order(V[v].size() - k) << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}