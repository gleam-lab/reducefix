#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> parent(MAXN);
vector<int> size(MAXN);
vector<vector<int>> largest(MAXN);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        vector<int> merged;
        merge(largest[a].rbegin(), largest[a].rend(),
              largest[b].rbegin(), largest[b].rend(),
              back_inserter(merged), greater<int>());
        if (merged.size() > 10)
            merged.resize(10);
        largest[a] = vector<int>(merged.rbegin(), merged.rend());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
        largest[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u;
        if (op == 1) {
            cin >> v;
            union_sets(u, v);
        } else {
            int k;
            cin >> k;
            int root = find_set(u);
            if (largest[root].size() < k) {
                cout << "-1\n";
            } else {
                cout << largest[root][largest[root].size() - k] << '\n';
            }
        }
    }

    return 0;
}