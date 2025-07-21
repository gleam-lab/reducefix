#include<bits/stdc++.h>
using namespace std;
vector<int> graph[200005]; // Adjacency list for the graph
vector<int> vertex_list;   // To store unique vertices in sorted order
map<int, int> vertex_index; // Maps vertex number to its index in vertex_list

int find(int v) {
    if (vertex_index.find(v) == vertex_index.end()) {
        vertex_index[v] = vertex_list.size();
        vertex_list.push_back(v);
        sort(vertex_list.begin(), vertex_list.end());
    }
    return vertex_index[v];
}

int main() {
    int n, q;
    cin >> n >> q;

    int op, u, v, index;

    while (q--) {
        cin >> op >> u >> v;

        if (op == 1) { // Add edge
            index = find(u);
            graph[index].push_back(v);
            graph[find(v)].push_back(u);

            // If the new edge connects components, merge them by pushing the smaller component into the larger one
            if (find(u) != find(v)) {
                if (graph[index].size() > graph[find(v)].size()) {
                    swap(index, find(v));
                }
                for (int node : graph[find(v)]) {
                    graph[index].push_back(node);
                    if (vertex_index.find(node) == vertex_index.end()) {
                        vertex_index[node] = vertex_list.size();
                        vertex_list.push_back(node);
                        sort(vertex_list.begin(), vertex_list.end());
                    }
                    find(node); // Update the index of the node and re-sort if necessary
                }
                graph[find(v)].clear(); // Clear the smaller component's adjacency list
            }
        } else if (op == 2) { // Query the k-th largest vertex
            int v_index = find(v);
            int k = v - 1; // Adjust k to be zero-indexed
            if (k >= (int)vertex_list.size()) {
                cout << -1 << endl;
            } else {
                cout << vertex_list[vertex_list.size() - 1 - k] << endl;
            }
        }
    }

    return 0;
}