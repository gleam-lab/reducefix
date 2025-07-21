#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[200001];
int n, m;
vector<int> depth(200001, 100000000); // Using large number to represent initial depth
vector<bool> visited(200001, false);
int startNode = 1;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming undirected graph
    }
    visited[startNode] = true;
    depth[startNode] = 0;
    dfs(startNode);
    cout << depth[1] << endl; // Output depth for node 1
    return 0;
}