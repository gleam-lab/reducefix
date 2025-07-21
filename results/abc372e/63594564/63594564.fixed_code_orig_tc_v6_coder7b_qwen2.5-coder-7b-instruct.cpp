#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

int parent[MAXN];
int rank[MAXN];

// Union-Find operations
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
    }
}

// Function to get the k-th largest element in a sorted set
int kthLargest(vector<int>& s, int k) {
    if (k > s.size()) return -1;
    return s[s.size() - k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    // Initialize Union-Find
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<set<int>> adj(n + 1);

    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            // Union operation
            int pu = find(u), pv = find(v);
            if (pu != pv) {
                if (adj[pu].size() < adj[pv].size())
                    swap(pu, pv);
                for (int x : adj[pv])
                    adj[pu].insert(x);
                adj[pv].clear();
                unite(u, v);
            }
        } else {
            // Query operation
            int pu = find(u);
            cout << kthLargest(adj[pu], v) << '\n';
        }
    }

    return 0;
}