#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int N = 2e5 + 5;
int parent[N];
ordered_set elements[N];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (elements[u].size() < elements[v].size()) swap(u, v);
    
    parent[v] = u;
    for (auto x : elements[v]) {
        elements[u].insert(x);
    }
    elements[v].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        elements[i].insert(i);
    }
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            
            if (elements[v].size() < k) {
                cout << -1 << '\n';
            } else {
                cout << *elements[v].find_by_order(elements[v].size() - k) << '\n';
            }
        }
    }
    
    return 0;
}