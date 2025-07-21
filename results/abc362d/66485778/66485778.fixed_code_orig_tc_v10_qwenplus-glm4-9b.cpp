#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_N = 2 * 10^5 + 10;

vector<vector<int>> dist(MAX_N, vector<int>(MAX_N, INT_MAX / 2));
vector<int> vertex_weights(MAX_N);
vector<vector<pair<int, int>>> graph(MAX_N); // adjacency list

void read_graph(int n, int m) {
    // Initialize the distance matrix to infinity
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    // Read the weights of the vertices
    for (int i = 0; i < n; ++i) {
        cin >> vertex_weights[i];
    }
    // Read the edges
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }
    // Initialize the distance matrix with the read edge weights
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        dist[u][v] = b;
        dist[v][u] = b;
    }
}

void floyd_warshall(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void print_min_weights(int n) {
    for (int i = 2; i < n; ++i) {
        cout << dist[0][i] + vertex_weights[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    read_graph(n, m);
    floyd_warshall(n);
    print_min_weights(n);
    return 0;
}