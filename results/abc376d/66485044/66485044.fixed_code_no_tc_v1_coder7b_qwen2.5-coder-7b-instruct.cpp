#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN];
int dist[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    memset(dist, -1, sizeof(dist));
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : vec[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (dist[v] >= dist[u]) { // Cycle detected
                cout << dist[v] - dist[u] + 1 << endl; // Minimum length of cycle
                exit(0); // Exit after finding the cycle
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
    }

    bfs(1);

    cout << "-1" << endl; // No cycle found
    return 0;
}