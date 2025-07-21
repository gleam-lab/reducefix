#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define vi vector<int>
#define vb vector<bool>

const int MAXN = 2 * 100005;

vi parent(MAXN);
vi rank(MAXN);
vi size(MAXN);
vb visited(MAXN);

void init(int n) {
    iota(parent.begin(), parent.end(), 0);
    fill(rank.begin(), rank.end(), 0);
    fill(size.begin(), size.end(), 1);
    fill(visited.begin(), visited.end(), false);
}

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

bool unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return false;
    if (rank[pu] > rank[pv])
        swap(pu, pv);
    parent[pu] = pv;
    size[pv] += size[pu];
    if (rank[pu] == rank[pv])
        rank[pv]++;
    return true;
}

int kthLargest(int u, int k) {
    int pu = find(u);
    if (size[pu] < k) return -1;
    priority_queue<int> pq;
    for (int i = 1; i <= size[pu]; ++i) {
        int v = find(i);
        if (!visited[v]) {
            visited[v] = true;
            pq.push(-i);
        }
    }
    while (--k && !pq.empty()) pq.pop();
    return -pq.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            unite(u, v);
        } else {
            int result = kthLargest(v, k);
            cout << result << '\n';
        }
    }

    return 0;
}