#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex {
    int id;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap for k-th largest
};

vector<Vertex> graph;
int parent[200005];

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void union_vertices(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        parent[root_v] = root_u;
        // Merge priority queues
        while (!graph[root_u].pq.empty() && graph[root_u].pq.size() + graph[root_v].pq.size() > 10) {
            graph[root_v].pq.push(graph[root_u].pq.top());
            graph[root_u].pq.pop();
        }
        graph[root_u].pq.merge(graph[root_v].pq);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize graph and parent array
    graph.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        graph[i].id = i;
    }

    int u, v;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        if (u == 1) { // Type 1 query (add edge)
            union_vertices(u, v);
        } else { // Type 2 query (k-th largest)
            int root_v = find(v);
            if (graph[root_v].pq.size() < v) {
                cout << -1 << '\n';
            } else {
                cout << graph[root_v].pq.top() << '\n';
                graph[root_v].pq.pop(); // Remove the k-th largest element
            }
        }
    }

    return 0;
}