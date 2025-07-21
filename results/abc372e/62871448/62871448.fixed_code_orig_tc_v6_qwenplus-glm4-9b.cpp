#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> size;
vector<priority_queue<int, vector<int>, greater<int>>> pq;

int root(int x) {
    if (parent[x] == x) return x;
    int rootX = root(parent[x]);
    parent[x] = rootX; // Path compression
    return rootX;
}

void union_sets(int x, int y) {
    int rootX = root(x);
    int rootY = root(y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
            pq[rootY].merge(pq[rootX]);
            pq[rootX].clear();
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            pq[rootX].merge(pq[rootY]);
            pq[rootY].clear();
        }
    }
}

int kth_largest(int v, int k) {
    int rootV = root(v);
    if (size[rootV] < k) {
        return -1;
    }
    int count = 0;
    while (!pq[rootV].empty()) {
        count++;
        if (count == k) {
            return pq[rootV].top();
        }
        pq[rootV].pop();
    }
    return -1; // This should never happen if size[rootV] >= k
}

int main() {
    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    pq.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        pq[i].push(i);
    }
    int u, v, k;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        if (u == 1) {
            union_sets(u, v);
        } else {
            cin >> k;
            cout << kth_largest(v, k) << '\n';
        }
    }
    return 0;
}