#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> parent(MAXN);
vector<int> rank_(MAXN);
vector<vector<int>> top_nodes(MAXN);

void make_set(int v) {
    parent[v] = v;
    rank_[v] =0;
    top_nodes[v] = {v};
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        top_nodes[a].insert(top_nodes[a].end(), top_nodes[b].begin(), top_nodes[b].end());
        sort(top_nodes[a].rbegin(), top_nodes[a].rend());
        if (top_nodes[a].size() > 10)
            top_nodes[a].resize(10);
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        make_set(i);
    }

    while (Q--) {
        int type, u, v;
        cin >> type >> u;
        if (type == 1) {
            cin >> v;
            union_sets(u, v);
        } else {
            int k;
            cin >> k;
            int root = find_set(u);
            if (top_nodes[root].size() >= k) {
                cout << top_nodes[root][k - 1] << '\n';
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}