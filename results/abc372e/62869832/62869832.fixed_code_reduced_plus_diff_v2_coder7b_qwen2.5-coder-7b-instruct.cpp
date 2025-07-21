#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN), rank(MAXN), sortedSet[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    
    if (rank[px] > rank[py]) {
        parent[py] = px;
        sortedSet[px].insert(sortedSet[py].begin(), sortedSet[py].end());
        sortedSet[py].clear();
    } else {
        parent[px] = py;
        sortedSet[py].insert(sortedSet[px].begin(), sortedSet[px].end());
        sortedSet[px].clear();
        
        if (rank[px] == rank[py]) {
            rank[py]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        sortedSet[i].push_back(i);
    }

    while (q--) {
        int type, u, v, k;
        cin >> type;

        if (type == 1) {
            cin >> u >> v;
            unite(u, v);
        } else {
            cin >> u >> k;
            int root = find(u);
            if (sortedSet[root].size() >= k) {
                cout << *next(sortedSet[root].rbegin(), k - 1) << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}