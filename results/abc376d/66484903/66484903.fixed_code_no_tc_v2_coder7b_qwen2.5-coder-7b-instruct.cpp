#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN];
queue<int> q;
bool visited[MAXN];

// Function to perform BFS and find the shortest path to node 1
int bfs(int start) {
    queue<int> q;
    vector<int> dist(MAXN, INF); // Distance array initialized to infinity
    dist[start] = 0; // Distance to starting node is 0
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : vec[u]) {
            if (dist[v] == INF) { // If v has not been visited
                dist[v] = dist[u] + 1; // Update distance
                q.push(v);
            } else if (dist[v] > dist[u] + 1) { // Cycle detected
                return dist[u] - dist[v] + 1; // Return length of cycle
            }
        }
    }

    return -1; // No cycle found
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
    }

    int result = bfs(1); // Perform BFS starting from node 1

    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}