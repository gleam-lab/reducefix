#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9+7;

class DSU {
public:
    vector<int> parent, rank;
    vector<set<int>> components;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 1);
        components.resize(n + 1);
        for(int i=1; i<=n; ++i) components[i].insert(i);
    }

    int find(int x) {
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
        components[x].insert(components[y].begin(), components[y].end());
        components[y].clear();
    }

    set<int>& getComponent(int x) {
        return components[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    DSU dsu(n);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            auto &comp = dsu.getComponent(v);
            if(k > comp.size()) cout << -1 << '\n';
            else cout << *next(comp.rbegin(), k - 1) << '\n';
        }
    }

    return 0;
}