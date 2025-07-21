#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
#define all(v) v.begin(), v.end()

struct Union_Find {
    vector<int> par, sz;
    vector<priority_queue<int, vector<int>, greater<int>>> top_k;

    Union_Find(int n) {
        par.resize(n);
        sz.resize(n, 1);
        top_k.resize(n);
        rep(i, n) {
            par[i] = i;
            top_k[i].push(i + 1); // vertices are 1-based
            if (top_k[i].size() > 10) top_k[i].pop();
        }
    }

    int root(int v) {
        if (par[v] == v) return v;
        return par[v] = root(par[v]);
    }

    void merge(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        
        priority_queue<int> merged;
        while (!top_k[u].empty()) {
            merged.push(top_k[u].top());
            top_k[u].pop();
        }
        while (!top_k[v].empty()) {
            merged.push(top_k[v].top());
            top_k[v].pop();
        }
        while (!merged.empty() && top_k[u].size() < 10) {
            top_k[u].push(merged.top());
            merged.pop();
        }
    }

    int query(int v, int k) {
        v = root(v);
        if (top_k[v].size() < k) return -1;
        vector<int> temp;
        while (!top_k[v].empty()) {
            temp.push_back(top_k[v].top());
            top_k[v].pop();
        }
        int result = temp[temp.size() - k];
        for (int num : temp) {
            top_k[v].push(num);
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);

    rep(i, q) {
        int ty, u, v;
        cin >> ty >> u >> v;
        if (ty == 1) {
            u--; v--;
            uf.merge(u, v);
        } else {
            u--;
            int res = uf.query(u, v);
            cout << res << '\n';
        }
    }

    return 0;
}