#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

template<typename T>
using V = vector<T>;
using Edge = pair<int, int>; // pair <target_vertex, edge_weight>
using AdjacencyList = VEdges; // vector of Edges

using Graph = AdjacencyList;
using Distance = V<int>;
using Queue = priority_queue<Node, vector<Node>, greater<Node>>;

struct Node {
    int vertex, cost;
    Node(int vertex, int cost) : vertex(vertex), cost(cost) {}
    bool operator>(const Node& other) const {
        return cost > other.cost; // Max-heap based on cost
    }
};

int n, m;
int vertexWeight[200001];
AdjacencyList graph(200001);
Distance minDistance(200001, INF);

void dijkstra(int start) {
    Queue pq;
    pq.emplace(start, vertexWeight[start]);
    minDistance[start] = vertexWeight[start]; // Starting point's distance to itself is its own weight

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (minDistance[current.vertex] < current.cost) continue; // Skip if we have already found a better path

        for (auto& edge : graph[current.vertex]) {
            int nextVertex = edge.first;
            int edgeWeight = edge.second;

            if (minDistance[current.vertex] + edgeWeight < minDistance[nextVertex]) {
                minDistance[nextVertex] = minDistance[current.vertex] + edgeWeight;
                pq.emplace(nextVertex, minDistance[nextVertex]);
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> vertexWeight[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    dijkstra(1); // Start Dijkstra's from vertex 1

    for (int i = 2; i <= n; ++i) {
        cout << minDistance[i] << " ";
    }
    cout << endl;

    return 0;
}