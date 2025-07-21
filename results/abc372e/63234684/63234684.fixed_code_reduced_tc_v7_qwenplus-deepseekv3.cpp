#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
#define all(v) v.begin(), v.end()

struct Union_Find {
    vector<int> par;
    vector<multiset<int>> top;

    Union_Find(int n) {
        par.resize(n, -1);
        top.resize(n);
        rep(i,n) top[i].insert(i);
    }

    int root(int v) {
        if(par[v] == -1) return v;
        return par[v] = root(par[v]);
    }

    void merge(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) return;
        
        if(top[x].size() < top[y].size()) swap(x, y);
        
        for(auto val : top[y]) {
            top[x].insert(val);
            if(top[x].size() > 10) {
                top[x].erase(top[x].begin());
            }
        }
        top[y].clear();
        par[y] = x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    Union_Find uf(n);
    
    while(q--) {
        int ty, v, k;
        cin >> ty >> v >> k;
        v--;
        if(ty == 1) {
            k--;
            uf.merge(v, k);
        } else {
            int r = uf.root(v);
            if(uf.top[r].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = uf.top[r].end();
                advance(it, -k);
                cout << *it + 1 << "\n";
            }
        }
    }
}