#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <set<int>> components;
vector <int> parent;

int find_root(int x) {
    if(parent[x] != x)
        parent[x] = find_root(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int ra = find_root(a), rb = find_root(b);
    if(ra == rb) return;

    // Merge smaller set into larger one for efficiency
    if(components[ra].size() < components[rb].size()) swap(ra, rb);

    for(int node : components[rb]) {
        components[ra].insert(node);
        parent[node] = ra;
    }

    components[rb].clear(); // Optional cleanup
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    components.resize(n+1);
    parent.resize(n+1);

    for(int i = 1; i <= n; ++i) {
        components[i].insert(i);
        parent[i] = i;
    }

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1) {
            unite(a, b);
        } else {
            int root = find_root(a);
            if((int)components[root].size() < b) {
                cout << -1 << '\n';
            } else {
                auto it = components[root].rbegin();
                for(int i = 0; i < b-1; ++i) ++it;
                cout << *it << '\n';
            }
        }
    }

    return 0;
}