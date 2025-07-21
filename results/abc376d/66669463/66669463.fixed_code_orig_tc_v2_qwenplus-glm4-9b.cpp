#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN]; // Adjacency list for the graph
int n, m; // Number of vertices and edges
int dist[MAXN]; // Distance array to store the shortest path distance from source to each vertex

// Read input
int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res * 10) + (c - '0'), c = getchar();
    return res;
}

// Add edge to the adjacency list
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS to find the shortest path from source to all other vertices
void dfs(int u, int d) {
    dist[u] = d;
    for (int v : adj[u]) {
        if (dist[v] == -1) dfs(v, d + 1);
    }
}

int main() {
    n = read();
    m = read();

    // Initialize distance array with -1 (unvisited)
    fill(dist, dist + n + 1, -1);

    // Read edges and construct the graph
    int u, v;
    for (int i = 0; i < m; ++i) {
        u = read();
        v = read();
        addEdge(u, v);
    }

    // Perform DFS from vertex 1 (assuming vertex 1 is the source)
    dfs(1, 0);

    // Output the shortest path distance from vertex 1 to vertex 1 (itself)
    if (dist[1] == -1) {
        cout << "-1" << endl;
    } else {
        cout << dist[1] << endl;
    }

    return 0;
}