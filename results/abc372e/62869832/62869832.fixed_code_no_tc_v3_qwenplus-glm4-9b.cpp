#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
vector<int> anss;

struct Query {
    int type, u, v, k;
};

vector<Query> queries;

int find_root(int u) {
    if (u != graph[u].back()) {
        graph[u].push_back(find_root(graph[u].back()));
    }
    return graph[u].back();
}

void union_nodes(int u, int v) {
    int root_u = find_root(u);
    int root_v = find_root(v);
    if (root_u != root_v) {
        graph[root_u].insert(graph[root_u].end(), graph[root_v].begin(), graph[root_v].end());
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int type, u, v, k;
        cin >> type >> u >> v;
        queries.push_back({type, u, v, k});
    }

    sort(queries.begin(), queries.end());

    // Initialize graph with all nodes as their own roots
    for (int i = 1; i <= n; i++) {
        graph[i].push_back(i);
    }

    // Process queries, but only type 1 for now
    for (auto& q : queries) {
        if (q.type == 1) {
            union_nodes(q.u, q.v);
        }
    }

    // Now process type 2 queries
    for (auto& q : queries) {
        if (q.type == 2) {
            int root_v = find_root(q.v);
            if (root_v == q.v) {
                // Collect all vertices in the connected component of v
                vector<int> connected_vertices;
                for (int node : graph[root_v]) {
                    if (node != root_v) {
                        connected_vertices.push_back(node);
                    }
                }

                // Sort the vertices to find the k-th largest
                sort(connected_vertices.begin(), connected_vertices.end(), greater<int>());
                if (q.k <= connected_vertices.size()) {
                    anss.push_back(connected_vertices[q.k - 1]);
                } else {
                    anss.push_back(-1);
                }
            } else {
                anss.push_back(-1); // Should never reach here in the given problem constraints
            }
        }
    }

    // Output answers to type 2 queries
    for (int ans : anss) {
        cout << ans << '\n';
    }

    return 0;
}