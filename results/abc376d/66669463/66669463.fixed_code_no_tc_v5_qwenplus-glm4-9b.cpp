#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

const int N = 200001;

struct edge {
    int to;
};

vector<edge> graph[N];
bitset<N> visited;
int ans[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        graph[i].clear();
        ans[i] = 100000000; // Initialize with large values
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v});
    }

    // Depth-First Search to find the minimum distance from node 1 to node 1
    function<void(int, int)> dfs = [&](int node, int depth) {
        if (node == 1 && depth < ans[1]) {
            ans[1] = depth;
        }
        visited[node] = 1;
        for (edge &e : graph[node]) {
            if (!visited[e.to]) {
                dfs(e.to, depth + 1);
            }
        }
    };

    dfs(1, 0);

    // If ans[1] is still 100000000, it means no path was found
    if (ans[1] == 100000000) {
        cout << "-1" << endl;
    } else {
        cout << ans[1] << endl;
    }

    return 0;
}