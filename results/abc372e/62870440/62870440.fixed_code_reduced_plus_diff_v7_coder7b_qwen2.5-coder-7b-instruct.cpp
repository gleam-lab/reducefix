#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
const int MAX_Q = 200005;

vector<int> adj[MAX_N];
int parent[MAX_N];
int rank[MAX_N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        adj[i].clear();
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    
    if (rank[x] > rank[y]) {
        parent[y] = x;
        adj[x].insert(adj[x].end(), adj[y].begin(), adj[y].end());
        adj[y].clear();
    } else {
        parent[x] = y;
        adj[y].insert(adj[y].end(), adj[x].begin(), adj[x].end());
        adj[x].clear();
        if (rank[x] == rank[y]) rank[y]++;
    }
    sort(adj[y].begin(), adj[y].end());
}

vector<int> getKthLargest(vector<vector<int>>& queries, int n, int q) {
    vector<int> result(q, -1);
    init(n);

    int qi = 0;
    for (int i = 0; i < q; ++i) {
        if (queries[i][0] == 1) {
            unite(queries[i][1], queries[i][2]);
        } else {
            int v = queries[i][1];
            int k = queries[i][2];
            int p = find(v);
            if (adj[p].size() >= k) {
                result[qi++] = adj[p][k - 1];
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> result = getKthLargest(queries, n, q);

    for (int r : result) {
        cout << r << "\n";
    }

    return 0;
}