#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par, rank, pq;
    vector<vector<int>> uni;

    Union_Find(int n) {
        par.resize(n, -1);
        sz.resize(n, 1);
        pq.resize(n);
        rank.resize(n, 0);
        rep(i, n) pq[i] = (priority_queue<int, vector<int>, greater<int>>) {i};
        uni.resize(n);
        rep(i, n) uni[i].push_back(i);
    }
    
    int root(int v) {
        if (par[v] == -1) return v;
        else par[v] = root(par[v]);
        return par[v];
    }
    
    void merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        sz[x] += sz[y];
        if (rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        auto &q1 = pq[x], &q2 = pq[y];
        while (!q2.empty()) {
            q1.push(q2.top());
            q2.pop();
        }
        pq[y] = q1;
        sort(q1.begin(), q1.end());
        while (q1.size() > 9) q1.pop();
    }
    
    int size(int v) {
        return sz[root(v)];
    }
    
    int kth_largest(int v, int k) {
        int r = root(v);
        if (size(root(v)) < k) return -1;
        auto &q = pq[r];
        for (int i = 0; i < k; i++) {
            if (q.empty()) return -1;
            if (i == k - 1) return q.top() + 1; // Return 1-based index
            q.pop();
        }
        return -1;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);
    
    for (int i = 0; i < q; i++) {
        int ty, u, v, k;
        cin >> ty >> u >> v;
        if (ty == 1) {
            uf.merge(u, v);
        } else {
            cin >> k;
            cout << uf.kth_largest(u, k) << endl;
        }
    }
}