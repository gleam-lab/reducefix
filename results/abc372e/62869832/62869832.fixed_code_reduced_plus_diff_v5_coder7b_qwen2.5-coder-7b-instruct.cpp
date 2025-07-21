#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;

vector<int> parent(MAXN), rank(MAXN), size(MAXN);
multiset<int> connections[MAXN];

void init(int n) {
    iota(parent.begin(), parent.end(), 0);
    fill(rank.begin(), rank.end(), 0);
    fill(size.begin(), size.end(), 1);
}

int find(int x) {
    if (parent[x] != x) {
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
        size[x] += size[y];
        connections[x].insert(connections[y].begin(), connections[y].end());
        connections[x].erase(connections[x].find(size[y]));
        connections[x].insert(size[x]);
    } else {
        parent[x] = y;
        size[y] += size[x];
        connections[y].insert(connections[x].begin(), connections[x].end());
        connections[y].erase(connections[y].find(size[x]));
        connections[y].insert(size[y]);
        if (rank[x] == rank[y]) rank[y]++;
    }
}

int getKthLargest(int node, int k) {
    node = find(node);
    auto it = connections[node].upper_bound(k);
    if (it == connections[node].begin()) return -1;
    it--;
    return *it;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            cin >> u >> k;
            cout << getKthLargest(u, k) << '\n';
        }
    }

    return 0;
}