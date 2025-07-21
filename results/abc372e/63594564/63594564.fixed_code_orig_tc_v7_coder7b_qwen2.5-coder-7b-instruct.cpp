#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

const int MAXN = 2e5 + 5;

vector<int> parent(MAXN), rank(MAXN);
multiset<int> neighbors[MAXN];

int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    
    if (rank[x] > rank[y])
        swap(x, y);
    
    parent[x] = y;
    if (rank[x] == rank[y])
        rank[y]++;
    
    // Merge the multisets
    auto it = neighbors[x].begin();
    while(it != neighbors[x].end()) {
        neighbors[y].insert(*it++);
    }
    neighbors[x].clear();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Initialize Union-Find
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        neighbors[i].insert(i);
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 1) {
            // Add an edge between u and v
            unite(u, v);
        } else {
            // Find the representative of u
            int rep = find(u);
            
            // Check if there are at least k neighbors
            if (neighbors[rep].size() < v) {
                cout << "-1\n";
            } else {
                // Get the k-th largest neighbor
                auto it = neighbors[rep].rbegin();
                advance(it, v - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}