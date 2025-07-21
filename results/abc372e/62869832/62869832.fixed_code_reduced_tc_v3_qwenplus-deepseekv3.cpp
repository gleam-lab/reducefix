#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int parent[MAXN];
vector<int> top_elements[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v) return;

    if (top_elements[root_u].size() < top_elements[root_v].size()) {
        swap(root_u, root_v);
    }

    vector<int> merged;
    merged.reserve(top_elements[root_u].size() + top_elements[root_v].size());
    merge(top_elements[root_u].begin(), top_elements[root_u].end(),
          top_elements[root_v].begin(), top_elements[root_v].end(),
          back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top_elements[root_u] = merged;
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_elements[i] = {i};
    }

    while (Q--) {
        int type, u, v;
        cin >> type >> u;
        if (type == 1) {
            cin >> v;
            merge(u, v);
        } else {
            int k;
            cin >> k;
            int root = find(u);
            if (top_elements[root].size() < k) {
                cout << "-1\n";
            } else {
                cout << top_elements[root][k - 1] << "\n";
            }
        }
    }

    return 0;
}