#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN];
queue<int> q;
int step[MAXN];
bool vis[MAXN];

int bfs(int start, int end) {
    memset(vis, false, sizeof(vis));
    memset(step, -1, sizeof(step));
    q.push(start);
    vis[start] = true;
    step[start] = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 0; i < vec[top].size(); ++i) {
            int to = vec[top][i];
            if (!vis[to]) {
                step[to] = step[top] + 1;
                q.push(to);
                vis[to] = true;
            }
            if (to == end) {
                return step[to];
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u); // Assuming undirected graph
    }

    int result = bfs(1, n);

    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}