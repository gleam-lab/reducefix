#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5 + 5;

vector<int> parent(N + 1);
vector<vector<int>> graph(N + 1);
vector<vector<int>> vertex_list(N + 1);
priority_queue<int, vector<int>, greater<int>> pq;

void find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void union_vertices(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (vertex_list[u].size() < 10) {
            vertex_list[u].insert(vertex_list[u].begin(), vertex_list[v].begin(), vertex_list[v].end());
            parent[v] = u;
        } else {
            vertex_list[v].insert(vertex_list[v].end(), vertex_list[u].begin() + 10, vertex_list[u].end());
            parent[u] = v;
        }
    }
}

void add_edge(int u, int v) {
    if (find(u) != find(v)) {
        vertex_list[find(u)].insert(vertex_list[find(u)].begin(), vertex_list[v].begin(), vertex_list[v].end());
        vertex_list[find(v)].clear();
        parent[v] = u;
    }
}

void process_query_2(int v, int k) {
    if (k > vertex_list[find(v)].size()) {
        cout << -1 << '\n';
    } else {
        cout << vertex_list[find(v)][k - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    fill(parent.begin(), parent.end(), -1);
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            add_edge(a, b);
        } else {
            process_query_2(a, b);
        }
    }

    return 0;
}