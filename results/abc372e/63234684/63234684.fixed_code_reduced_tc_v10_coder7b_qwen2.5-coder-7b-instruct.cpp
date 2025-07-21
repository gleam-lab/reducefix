#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank, size;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for(int i=0; i<n; ++i) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        if(rank[x] == rank[y]) rank[x]++;
    }

    int get_size(int x) {
        return size[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    UnionFind uf(n+1);
    priority_queue<int, vector<int>, greater<int>> pq[n+1];

    for(int i=0; i<q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if(type == 1) {
            uf.unite(u, v);
        } else {
            u = uf.find(u);
            if(pq[u].size() < v) cout << "-1\n";
            else {
                cout << pq[u].top() << "\n";
                pq[u].pop();
            }
        }
    }

    return 0;
}