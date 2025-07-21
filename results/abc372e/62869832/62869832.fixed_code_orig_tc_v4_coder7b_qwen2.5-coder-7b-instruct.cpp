#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN), rank(MAXN), size(MAXN);

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }
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
    } else {
        parent[x] = y;
        size[y] += size[x];
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
}

int getKthLargest(vector<int>& vec, int k) {
    sort(vec.begin(), vec.end());
    if (vec.size() < k) return -1;
    return vec[k - 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    init(n);
    
    vector<vector<int>> connectedSets(n + 1);
    
    while (q--) {
        int op, u, v, k;
        cin >> op;
        
        if (op == 1) {
            cin >> u >> v;
            unite(u, v);
        } else {
            cin >> u >> k;
            int root = find(u);
            connectedSets[root].clear();
            for (int i = 1; i <= n; ++i) {
                if (find(i) == root) {
                    connectedSets[root].push_back(i);
                }
            }
            cout << getKthLargest(connectedSets[root], k) << "\n";
        }
    }
    
    return 0;
}