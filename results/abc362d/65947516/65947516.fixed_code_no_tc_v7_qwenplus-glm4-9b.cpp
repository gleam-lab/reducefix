#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N]; // Distance array to store the minimum weight from vertex 1 to each vertex i
bool vis[N]; // Visited array to check if a vertex has been visited

// Define the graph as an adjacency list
vector<pii> g[N];

struct node {
    int id, dis;
    bool operator<(const node& x) const {
        return dis > x.dis; // Use less than to make the max-heap behave like a min-heap
    }
};

void dijkstra() {
    // Reset visited and distance arrays
    memset(vis, false, sizeof(vis));
    memset(dis, LLONG_MAX, sizeof(dis));
    dis[1] = 0; // Distance from vertex 1 to itself is 0

    priority_queue<node> q; // Priority queue for Dijkstra's algorithm
    q.push({1, 0}); // Start from vertex 1

    while (!q.empty()) {
        node now = q.top();
        q.pop();
        if (vis[now.id]) continue; // Skip if already visited
        vis[now.id] = true; // Mark the vertex as visited

        for (pii i : g[now.id]) { // Explore each adjacent vertex
            if (dis[i.first] > dis[now.id] + i.second + a[now.id]) {
                dis[i.first] = dis[now.id] + i.second + a[now.id]; // Update distance
                q.push({i.first, dis[i.first]}); // Push the new state into the queue
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w}); // Add edge from u to v
        g[v].push_back({u, w}); // Add edge from v to u (undirected graph)
    }

    dijkstra(); // Run Dijkstra's algorithm

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i] + a[i]); // Output the distance from vertex 1 to vertex i
    }
    printf("\n");

    return 0;
}