#include <vector>
#include <queue>
#include <climits>

using namespace std;

// ... (include other necessary headers and define constants)

vector<vector<long long>> graph(N);  // Adjacency list for the graph
vector<long long> vertex_weights(N); // Vertex weights
long long min_weight(N);

int main() {
    // Input vertices and edges
    // ...

    // Run the path finding algorithm
    long long min_path_weights[N - 1];
    rep(i, 1, N) {
        min_path_weights[i - 1] = min_weight(i);
    }

    // Output the results
    out(min_path_weights[1], min_path_weights[2], ..., min_path_weights[N - 1]);

    return 0;
}

// ... (Define the min_weight function using Dijkstra's or Floyd-Warshall algorithm)