#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;

struct UnionFind {
    vector<int> parent, rank;
    vector<set<int>> components;
    
    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i].insert(i);
        }
    }

    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;

        // Always merge smaller component into larger one
        if (components[rx].size() < components[ry].size())
            swap(rx, ry);

        parent[ry] = rx;
        components[rx].merge(components[ry]);
        components[ry].clear();

        return true;
    }

    set<int>& getComponent(int x) {
        return components[findRoot(x)];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<int> ans;

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;

            auto& comp = uf.getComponent(v);
            if ((int)comp.size() < k) {
                ans.push_back(-1);
            } else {
                auto it = comp.rbegin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for(auto x: ans) 
        cout << x << endl;

    return 0;
}