#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN), rank(MAXN);
vector<vector<int>> adjList(MAXN);

void init(int n) {
    iota(parent.begin(), parent.end(), 0);
    fill(rank.begin(), rank.end(), 1);
}

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] > rank[y]) swap(x, y);
    parent[x] = y;
    rank[y] += rank[x];
    adjList[y].insert(adjList[y].end(), adjList[x].begin(), adjList[x].end());
    sort(adjList[y].begin(), adjList[y].end(), greater<int>());
    adjList[x].clear();
}

int kthLargest(vector<int>& vec, int k) {
    if (vec.size() < k) return -1;
    return vec[k - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            --u, --v;
            unite(u, v);
        } else {
            cin >> u >> k;
            --u;
            cout << kthLargest(adjList[find(u)], k) << "\n";
        }
    }

    return 0;
}