#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN), rank(MAXN);
map<int, priority_queue<int, vector<int>, greater<int>>> max_heap;

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (x != parent[x]) {
        return parent[x] = find(parent[x]);
    }
    return x;
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] > rank[y]) {
        parent[y] = x;
        max_heap[x].merge(max_heap[y]);
    } else {
        parent[x] = y;
        max_heap[y].merge(max_heap[x]);
        if (rank[x] == rank[y]) rank[y]++;
    }
}

int getKthLargest(int x, int k) {
    int root = find(x);
    if (max_heap[root].size() < k) return -1;
    auto it = max_heap[root].begin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    init(n);
    
    while (q--) {
        int type, u, v, k;
        cin >> type;
        
        if (type == 1) {
            cin >> u >> v;
            unite(u, v);
        } else {
            cin >> u >> k;
            cout << getKthLargest(u, k) << "\n";
        }
    }
    
    return 0;
}