#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 2e5 + 5;

vector<int> parent(N);
vector<vector<int>> graph(N);
vector<vector<int>> vertex_list(N);

int find_set(int v) {
    if (parent[v] != v) {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}

void union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        parent[root_u] = root_v;
        vertex_list[root_u].insert(vertex_list[root_v].end(), vertex_list[root_v].begin(), vertex_list[root_v].end());
        vertex_list[root_u].sort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        vertex_list[i].push_back(i);
    }

    for (int i = 0; i < q; ++i) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root_v = find_set(v);
            if (op == 2) {
                if (vertex_list[root_v].size() < v) {
                    cout << -1 << '\n';
                } else {
                    cout << vertex_list[root_v][vertex_list[root_v].size() - v] << '\n';
                }
            }
        }
    }

    return 0;
}