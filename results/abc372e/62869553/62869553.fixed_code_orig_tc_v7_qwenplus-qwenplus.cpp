#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int TOP_K = 10;

int N, Q;
int parent[MAXN];
vector<int> top_members[MAXN];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets and maintain top TOP_K members
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v)
        return;

    // Always merge smaller into larger for efficiency
    if (top_members[root_u].size() < top_members[root_v].size())
        swap(root_u, root_v);

    // Move members from root_v to root_u
    for (int member : top_members[root_v])
        top_members[root_u].push_back(member);

    // Sort and keep top TOP_K elements
    sort(top_members[root_u].rbegin(), top_members[root_u].rend());
    if (top_members[root_u].size() > TOP_K)
        top_members[root_u].resize(TOP_K);

    // Update parent
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_members[i].push_back(i);
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (top_members[root].size() >= k)
                cout << top_members[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}