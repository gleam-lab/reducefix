#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;
const int TOP_K = 10;

int parent[MAX];
vector<int> top_members[MAX];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union by size or simply merge parents
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v)
        return;

    // Always attach smaller tree to bigger tree
    // To reduce number of pointer updates, we merge the top lists of smaller into larger
    if (top_members[root_u].size() < top_members[root_v].size())
        swap(root_u, root_v);

    // Merge the top members
    vector<int> merged;
    auto& list1 = top_members[root_u];
    auto& list2 = top_members[root_v];

    int i = 0, j = 0;
    while (i < list1.size() && j < list2.size()) {
        if (list1[i] > list2[j])
            merged.push_back(list1[i++]);
        else
            merged.push_back(list2[j++]);
        if (merged.size() == TOP_K)
            break;
    }

    while (i < list1.size() && merged.size() < TOP_K)
        merged.push_back(list1[i++]);
    while (j < list2.size() && merged.size() < TOP_K)
        merged.push_back(list2[j++]);

    top_members[root_u] = merged;
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_members[i] = {i};
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (top_members[root].size() < k)
                cout << -1 << endl;
            else
                cout << top_members[root][k - 1] << endl;
        }
    }

    return 0;
}