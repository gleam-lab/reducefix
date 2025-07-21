#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

vector<int> vec[MAXN];
queue<int> q;
bool vis[MAXN];
int step[MAXN];

int bfs(int start, int target) {
    memset(vis, false, sizeof(vis));
    memset(step, -1, sizeof(step));
    q.push(start);
    vis[start] = true;
    step[start] = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (auto to : vec[top]) {
            if (!vis[to]) {
                vis[to] = true;
                step[to] = step[top] + 1;
                q.push(to);
                if (to == target) {
                    return step[to];
                }
            }
        }
    }

    return -1;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u); // Assuming undirected graph
    }

    int result = bfs(1, n);
    cout << result << endl;

    return 0;
}